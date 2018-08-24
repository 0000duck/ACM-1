#include<cstdio>
#include<cstring>
using namespace std;

#define Mid ((l+r)>>1)
#define lson rt<<1,l,Mid
#define rson rt<<1|1,Mid+1,r
const int MAX = 8010;
int n;

int col[MAX<<2];
int vis[MAX<<2];
int ans[MAX<<2];
int pre = -1;

void pushDown(int rt)
{
    col[rt<<1] = col[rt<<1|1] = col[rt];
    col[rt] = -1;
}

void update(int rt, int l, int r, int L, int R, int color)
{
    if(L <= l && r <= R)
    {
        col[rt] = color;
        return;
    }
    if(col[rt] != -1)
        pushDown(rt);
    if(L <= Mid)
        update(lson,L,R,color);
    if(R > Mid)
        update(rson,L,R,color);
}

void query(int rt, int l, int r)
{
    if(col[rt] != -1)
    {
        for(int i=l; i<=r; i++)
            vis[i] = col[rt];
        col[rt] = -1;
        return;
    }
    if(l==r)
        return;
    query(lson);
    query(rson);
}

int main()
{
    while(~scanf("%d",&n))
    {
        memset(col,-1,sizeof(col));
        memset(vis,-1,sizeof(vis));
        memset(ans,0,sizeof(ans));
        int l,r,c;
        for(int i=0; i<n; i++)
        {
            scanf("%d %d %d",&l,&r,&c);
            update(1,1,8000,l+1,r,c);
        }
        query(1,1,8000);
        int pre = -1;
        for(int i=0; i<=8000; i++)
        {
            if(vis[i] != -1 && pre != vis[i])
                ans[vis[i]]++;
            pre = vis[i];
        }
        for(int i=0; i<=8000; i++)
            if(ans[i]!=0)
                printf("%d %d\n",i,ans[i]);
        printf("\n");
    }
    return 0;
}
