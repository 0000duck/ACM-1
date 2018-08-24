#include<bits/stdc++.h>
using namespace std;

#define Mid ((l+r)>>1)
#define lson rt<<1,l,Mid
#define rson rt<<1|1,Mid+1,r
#define ll long long
const int MAX = 100010;

ll seg[MAX<<2];
int mark[MAX<<2];

int n;

void pushUp(int rt)
{
    seg[rt] = seg[rt<<1] + seg[rt<<1|1];
    if(mark[rt<<1] == 1 && mark[rt<<1|1] == 1)
        mark[rt] = 1;
}

void build(int rt,int l, int r)
{
    mark[rt] = 0;
    if(l == r)
        scanf("%lld",&seg[rt]);
    else
    {
        build(lson);
        build(rson);
        pushUp(rt);
    }
}

ll query(int rt, int l, int r, int L, int R)
{
    if(L <= l && r <= R)
        return seg[rt];
    else
    {
        ll tmp = 0;
        if(L <= Mid)
            tmp += query(lson,L,R);
        if(R > Mid)
            tmp += query(rson,L,R);
        return tmp;
    }
}

void update(int rt, int l, int r, int L, int R)
{
    if(l == r)
    {
        seg[rt] = sqrt(seg[rt]);
        if(seg[rt] <= 1)
            mark[rt] = 1;
        return;
    }
    if(L <= Mid && mark[rt<<1] != 1)
        update(lson,L,R);
    if(R > Mid && mark[rt<<1|1] != 1)
        update(rson,L,R);
    pushUp(rt);
}

int main()
{
    int T = 1;
    while(~scanf("%d",&n))
    {
        printf("Case #%d:\n",T++);
        build(1,1,n);
        int q;
        scanf("%d",&q);
        int o,l,r;
        while(q--)
        {
            scanf("%d %d %d",&o,&l,&r);
            if(l > r)
                swap(l,r);
            if(o)
                printf("%lld\n",query(1,1,n,l,r));
            else
                update(1,1,n,l,r);
        }
        printf("\n");
    }
    return 0;
}
