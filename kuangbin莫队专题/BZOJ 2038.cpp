#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#define ll long long
using namespace std;

const int maxn = 1e5 +10;


struct node{
    ll l,r;
    int id;
}q[maxn];

ll col[maxn];
ll Ans;    //记录当前组合数
ll ans[maxn];
ll fenmu[maxn];
ll tol[maxn];  //记录颜色
int n,m;
int len;

bool cmp(node a, node b)
{
    if (a.l/len == b.l/len )
        return a.r < b.r;
    return a.l/len < b.l/len;
}

void add(int x)
{
    Ans += tol[col[x]]++;
}

void dele(int x)
{
    Ans -= --tol[col[x]];
}

int main()
{
    while(~scanf("%d %d",&n,&m))
    {
        len = (int)sqrt(n);
        memset(tol,0,sizeof(tol));
        for(int i=1; i<=n; i++)
            scanf("%lld",&col[i]);
        for(int i=1; i<=m; i++)
        {
            scanf("%lld %lld",&q[i].l,&q[i].r);
            q[i].id = i;
        }
        sort(q+1,q+1+m,cmp);
        int l=q[1].l,r=q[1].r;
        Ans = 0;
        for(int i=l; i<=r; i++)
            add(i);
        for(int i=1; i<=m; i++)
        {
            while(q[i].l > l)
                dele(l++);
            while(q[i].l < l)
                add(--l);
            while(q[i].r > r)
                add(++r);
            while(q[i].r < r)
                dele(r--);

            ans[q[i].id] = Ans;
            ll tmp = q[i].r-q[i].l+1;
            fenmu[q[i].id] = tmp*(tmp-1)/2;
        }
        for(int i=1; i<=m; i++)
        {
            ll gcd = __gcd(ans[i],fenmu[i]);
            printf("%lld/%lld\n",ans[i]/gcd,fenmu[i]/gcd);
        }
    }
    return 0;
}
