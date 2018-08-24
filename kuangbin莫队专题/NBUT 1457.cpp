#include<algorithm>
#include<math.h>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
#define ll long long
const int maxn = 1e5+10;

struct node{
    int l,r;
    int id;
}q[maxn];

struct discre{
    ll num;
    int pos;
};

ll num[maxn];
ll cnt[maxn];
ll ans[maxn];
ll Ans;
int N,Q,len;

bool cmp(node a, node b)
{
    if(a.l/len == b.l/len)
        return a.r<b.r;
    return a.l/len < b.l/len;
}

bool cmpDis(discre a, discre b)
{
    return a.num < b.num;
}

void Discretize()
{
    vector<discre> v;
    discre tmp;
    for(int i=1; i<=N; i++)
    {
        scanf("%d",&tmp.num);
        tmp.pos = i;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end(),cmpDis);
    ll rec = 1;
    tmp = v[0];
    num[tmp.pos] = rec;
    for(int i=1; i<N; i++)
    {
        if(v[i].num != tmp.num)
            rec++;
        tmp = v[i];
        num[tmp.pos] = rec;
    }
}

ll cube(ll x)
{
    return x*x*x;
}

void add(int x)
{
    Ans -= cube(cnt[num[x]]);
    Ans += cube(++cnt[num[x]]);
}

void dele(int x)
{
    Ans -= cube(cnt[num[x]]);
    Ans += cube(--cnt[num[x]]);
}

int main()
{
    while(~scanf("%d",&N))
    {

        len = (int)sqrt(N);
        memset(cnt,0,sizeof(cnt));
        Discretize();
//        for(int i=1; i<=N; i++)
//            printf("%lld\n",num[i]);
        scanf("%d",&Q);
        for(int i=1; i<=Q; i++)
        {
            scanf("%d %d",&q[i].l,&q[i].r);
            q[i].id = i;
        }
        sort(q+1,q+1+Q,cmp);
//        int l=q[0].l,r=q[0].r;
//        Ans = 0;
//        for(int i=l; i<=r; i++)
//            add(i);
        int l=0,r=0;
        Ans = 1;
        for(int i=1; i<=Q; i++)
        {
            while(q[i].l < l)
                add(--l);
            while(q[i].l > l)
                dele(l++);
            while(q[i].r < r)
                dele(r--);
            while(q[i].r > r)
                add(++r);

            ans[q[i].id] = Ans;
        }
        for(int i=1; i<=Q; i++)
            printf("%lld\n",ans[i]);
    }
    return 0;
}
