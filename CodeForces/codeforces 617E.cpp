#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e6+7;

int num[maxn];

struct query
{
    int l,r;
    int id;
    int block;
}q[maxn];

int n,k,m,len;
ll Ans=0;
ll ans[maxn];
int flag[maxn];

bool cmp(query a, query b)
{
    if(a.block == b.block)
        return a.r < b.r;
    return a.block < b.block;
}

void add(int x)
{
    Ans += flag[num[x]^k];
    flag[num[x]]++;
}

void dele(int x)
{
    flag[num[x]]--;
    Ans -= flag[num[x]^k];
}

int main()
{
    while(~scanf("%d %d %d",&n,&m,&k))
    {
        len = (int)sqrt(n);
        Ans = 0;
        memset(flag,0,sizeof(flag));
        flag[0] = 1;

        for(int i=1; i<=n; i++)
        {
            scanf("%d",&num[i]);
            num[i] ^= num[i-1];
        }
        for(int i=1; i<=m; i++)
        {
            scanf("%d %d",&q[i].l,&q[i].r);
            q[i].id = i;
            q[i].block = q[i].l/len;
        }
        sort(q+1,q+1+m,cmp);
        int l=1,r=0;
        for(int i=1; i<=m; i++)
        {
            while(q[i].l < l)
            {
                l--;
                add(l-1);
            }
            while(q[i].l > l)
            {
                dele(l-1);
                l++;
            }
            while(q[i].r < r)
            {
                dele(r);
                r--;
            }
            while(q[i].r > r)
            {
                r++;
                add(r);
            }
            ans[q[i].id] = Ans;
        }
        for(int i=1; i<=m; i++)
            printf("%I64d\n",ans[i]);
    }

    return 0;
}
