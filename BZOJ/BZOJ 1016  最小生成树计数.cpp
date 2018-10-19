#include<bits/stdc++.h>
using namespace std;

const int maxn = 110;
const int mod = 31011;
int n,m;
int f[maxn];
int cnt[maxn];

struct node{
    int u;
    int v;
    int w;
    bool operator<(node a) const{
        return w<a.w;
    }
}g[maxn];

vector<node> vv[1100];

void init()
{
    for(int i=1; i<=maxn; i++)
        f[i] = i;
}

int Find(int x)
{
    if(f[x] == x)
        return x;
    else
        return f[x] = Find(x);
}

int ffind(int x)
{
    return f[x]==x?x:ffind(x);
}
//  ������k�ֽڵ�Ŀ���ȡֵ
//  pΪv[k]���±�
//  nowΪ���
int dfs(int k, int p, int now)
{
    if(p == vv[k].size())    //����ѵ���βʱ ��ǰ���������������ͬȨֵ�ڵ�����ͬ ���˳�
        return now == cnt[k];
    int ret = 0, u, v;
    if(now < cnt[k])
    {
        u = ffind(vv[k][p].u);
        v = ffind(vv[k][p].v);
        if(u != v)
        {
            f[u] = v;   //����
            ret += dfs(k,p+1,now+1);
            f[v] = v;   //����
        }
    }
    if(now+vv[k].size()-p-1 >= cnt[k])
        ret += dfs(k,p+1,now);
    return ret;
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=1; i<=m; i++)
            scanf("%d %d %d",&g[i].u,&g[i].v,&g[i].w);
        sort(g+1,g+1+m);
        init();
        int ans,tot = 0;
        int chk=0;  //��¼����
        for(int i=1; i<=m; i++)
        {
            if(g[i].w > g[i-1].w) tot++;
            vv[tot].push_back(g[i]); //��¼Ȩֵ��ͬ�ĵ�
            int u = Find(g[i].u);
            int v = Find(g[i].v);
            if(u != v)
            {
                cnt[tot]++; //��ŵ�ǰ�������� ȨֵΪtot�ĵ����Ŀ
                f[u] = v;
                chk++;
            }
        }
        if(chk < n-1)
        {
            printf("0\n");
            continue;
        }
        ans = 1;
        init();
        for(int i=1; i<=tot; i++)
        {
            ans = (ans*dfs(i,0,0))%mod;
            for(int j=0; j<vv[i].size(); j++)
            {
                int u = Find(vv[i][j].u);
                int v = Find(vv[i][j].v);
                f[u] = v;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
