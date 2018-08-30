#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
priority_queue<int,vector<int>,greater<int> > q;
int n,m;

struct node{
    int l,r;
}query[maxn];

int ans[maxn],top;

bool cmp(node a, node b)
{
    if(a.l < b.l)
        return true;
    else if(a.l == b.l)
        return a.r < b.r;
    else
        return false;
}

void solve()
{
    while(!q.empty())
        q.pop();
    for(int i=1; i<=n; i++)
            q.push(i);
    top=0;
    memset(ans,-1,sizeof(ans));
    for(int i=query[0].l; i<=query[0].r; i++)
        ans[i] = q.top(), q.pop();
    int l=query[0].l,r=query[0].r;
    for(int i=1; i<m; i++)
    {
        if(query[i].l >= l && query[i].r <= r)  //区间包含
            continue;
        if(query[i].l >= l && query[i].l <= r && query[i].r > r)   //区间相交
        {
            for(int j=l; j<query[i].l; j++)
                q.push(ans[j]);
            for(int j=r+1; j<=query[i].r; j++)
                ans[j] = q.top(), q.pop();
        }
        if(query[i].l > r)  //区间相离
        {
            for(int j=l; j<=r; j++)
                q.push(ans[j]);
            for(int j=query[i].l; j<=query[i].r; j++)
                ans[j] = q.top(), q.pop();
        }
        l = query[i].l;
        r = query[i].r;
    }
    for(int i=1; i<=n; i++)
    {
        if(ans[i] == -1)
            ans[i] = 1;
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&n,&m);
        for(int i=0; i<m; i++)
        {
            scanf("%d %d",&query[i].l,&query[i].r);
        }
        sort(query,query+m,cmp);
        solve();
        printf("%d",ans[1]);
        for(int i=2; i<=n; i++)
            printf(" %d",ans[i]);
        cout<<endl;
    }
    return 0;
}
