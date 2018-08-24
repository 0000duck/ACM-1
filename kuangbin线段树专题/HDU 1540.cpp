#include<cstdio>
#include<algorithm>
#include<cstring>
#include<stack>
using namespace std;
const int maxn=5e4+7;
int ll[maxn<<2],rl[maxn<<2],ml[maxn<<2];

void build(int now,int l,int r)
{
    ll[now]=rl[now]=ml[now]=r-l+1;
    if(l==r)    return ;
    int mid=(l+r)>>1;
    build(now<<1,l,mid);
    build(now<<1|1,mid+1,r);
}

void update(int now,int l,int r,int p,int s)
{
    if(l==r)
    {
        if(s)   rl[now]=ll[now]=ml[now]=1;
        else    rl[now]=ll[now]=ml[now]=0;
        return ;
    }
    int mid=(l+r)>>1;
    if(p<=mid)   update(now<<1,l,mid,p,s);
    else update(now<<1|1,mid+1,r,p,s);
    ll[now]=ll[now<<1];
    rl[now]=rl[now<<1|1];
    ml[now]=max(ll[now<<1],rl[now<<1|1]);
    ml[now]=max(ml[now],rl[now<<1]+ll[now<<1|1]);
    if(ll[now<<1]==mid-l+1) ll[now]+=ll[now<<1|1];
    if(rl[now<<1|1]==r-mid) rl[now]+=rl[now<<1];
}

int query(int now,int l,int r,int p)
{
    if(ml[now]==r-l+1||ml[now]==0||l==r)  return ml[now];
    int mid=(l+r)>>1;
    if(p<=mid)
    {
        if(p>=mid-rl[now<<1]+1)
            return query(now<<1,l,mid,p)+query(now<<1|1,mid+1,r,mid+1);
        else return query(now<<1,l,mid,p);
    }
    else
    {
        if(p<=mid+ll[now<<1|1])
            return query(now<<1|1,mid+1,r,p)+query(now<<1,l,mid,mid);
        else return query(now<<1|1,mid+1,r,p);
    }
}

int main()
{
    char option[3];
    int n,m,v;
    while(~scanf("%d%d",&n,&m))
    {
        build(1,1,n);
        stack<int> s;
        for(int i=0;i<m;i++)
        {
            scanf("%s",option);
            if(option[0]=='D')
            {
                scanf("%d",&v);
                s.push(v);
                update(1,1,n,v,0);
            }
            else if(option[0]=='R')
            {
                v=s.top();s.pop();
                update(1,1,n,v,1);
            }
            else if(option[0]=='Q')
            {
                scanf("%d",&v);
                printf("%d\n",query(1,1,n,v));
            }
        }
    }
    return 0;
}
