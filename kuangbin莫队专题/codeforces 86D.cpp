#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2e6+10;

ll a[maxn];
ll cnt[maxn];
ll ans[maxn];
int n,t,len;
ll Ans;
struct node
{
    int l,r;
    int id;
    int block;
} q[maxn];

//如果左端点所在的块相同 把右端点按照左端点所在的块的奇偶性分类排序
bool cmp(node& a, node& b)
{
    if(a.block == b.block)
        return a.block&1? a.r<b.r : a.r>b.r ;
    return a.block < b.block;
}


inline void add(int x)
{
    Ans += ((cnt[a[x]]<<1)+1)*a[x];
    //Ans -= cnt[a[x]]*cnt[a[x]]*a[x];
    cnt[a[x]]++;
    //Ans += cnt[a[x]]*cnt[a[x]]*a[x];
}

inline void dele(int x)
{
    Ans -= ((cnt[a[x]]<<1)-1)*a[x];
    //Ans -= cnt[a[x]]*cnt[a[x]]*a[x];
    cnt[a[x]]--;
    //Ans += cnt[a[x]]*cnt[a[x]]*a[x];
}

int main()
{
    while(~scanf("%d %d",&n,&t))
    {
        len = sqrt(n);
        memset(cnt,0,sizeof(cnt));
        for(int i=1; i<=n; i++)
            scanf("%I64d",&a[i]);
        for(int i=1; i<=t; i++)
        {
            scanf("%d %d",&q[i].l,&q[i].r);
            q[i].id = i;
            q[i].block = q[i].l/len;
        }
        sort(q+1,q+1+t,cmp);
        int l=q[1].l,r=q[1].r;
        Ans = 0;
        for(int i=l; i<=r; ++i)
            add(i);
        for(int i=1; i<=t; ++i)
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
        for(int i=1; i<=t; ++i)
            printf("%I64d\n",ans[i]);
    }
    return 0;
}
