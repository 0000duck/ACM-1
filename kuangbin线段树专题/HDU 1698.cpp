#include<bits/stdc++.h>
using namespace std;

#define Mid ((l+r)>>1)
#define lson rt<<1,l,Mid
#define rson rt<<1|1,Mid+1,r

const int MAX = 100010;
int seg[MAX<<2];
int laz[MAX<<2];

void pushUp(int rt)
{
    seg[rt] = seg[rt<<1] + seg[rt<<1|1];
}

void pushDown(int rt, int l, int r)
{
    laz[rt<<1] = laz[rt<<1|1] = laz[rt];

    seg[rt<<1] = laz[rt]*(Mid-l+1);
    seg[rt<<1|1] = laz[rt]*(r-Mid);

    laz[rt] = 0;
}

void build(int rt, int l, int r)
{
    laz[rt] = 0;
    seg[rt] = r - l + 1;
    if(l == r)
        return ;
    build(lson);
    build(rson);
}

void update(int rt, int l, int r, int L, int R, int val)
{
    if(L <= l && r <= R)
    {
        laz[rt] = val;
        seg[rt] = (r-l+1)*val;
    }
    else
    {
        if(laz[rt])
            pushDown(rt,l,r);
        if(L <= Mid)
            update(lson,L,R,val);
        if(R > Mid)
            update(rson,L,R,val);
        pushUp(rt);
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    int ca = 1;
    while(T--)
    {
        int n;
        scanf("%d",&n);
        build(1,1,n);
        int q;
        scanf("%d",&q);
        int l,r,v;
        while(q--)
        {
            scanf("%d %d %d",&l,&r,&v);
            update(1,1,n,l,r,v);
        }
        printf("Case %d: The total value of the hook is %d.\n",ca++,seg[1]);
    }
    return 0;
}
