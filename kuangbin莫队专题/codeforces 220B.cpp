#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;

int a[maxn];
int ans[maxn];
int n,m,len;
struct node{
    int l,r;
    int id;
}q[maxn];
int mm[maxn];
int Ans;
bool cmp(node a, node b)
{
    if(a.l/len == b.l/len)
        return a.r<b.r;
    return a.l/len < b.l/len;
}

void add(int x)
{
    if(a[x] > 100000)
        return;
    if(mm[a[x]] == a[x])
    {
        mm[a[x]]++;
        Ans--;
    }
    else
    {
        mm[a[x]]++;
        if(mm[a[x]] == a[x])
            Ans++;
    }
}

void dele(int x)
{
    if(a[x] > 100000)
        return;
    if(mm[a[x]] == a[x])
    {
        mm[a[x]]--;
        Ans--;
    }
    else
    {
        mm[a[x]]--;
        if(mm[a[x]] == a[x])
            Ans++;
    }
}
int main()
{
    while(~scanf("%d %d",&n,&m))
    {
        len = sqrt(n);
        memset(mm,0,sizeof(mm));
        for(int i=1; i<=n; i++)
            scanf("%d",&a[i]);
        for(int i=1; i<=m; i++)
        {
            scanf("%d %d",&q[i].l,&q[i].r);
            q[i].id = i;
        }
        sort(q+1,q+1+m,cmp);
        int l=q[1].l,r=q[1].r;
        Ans = 0;
        for(int i=l; i<=r; i++)
            add(i);
        for(int i=1; i<=m; i++)
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
        for(int i=1; i<=m; i++)
            printf("%d\n",ans[i]);
    }
    return 0;
}
