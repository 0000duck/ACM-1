#include<cstdio>
using namespace std;

#define Mid ((l+r)>>1)
#define lson rt<<1,l,Mid
#define rson rt<<1|1,Mid+1,r
#define ll long long
const int MAX = 1010000;

ll se[MAX<<2],add[MAX<<2];

void pushUp(int rt)
{
    se[rt] = se[rt<<1] + se[rt<<1|1];
}

void pushDown(int rt, int l, int r)
{
    if(add[rt]!=0)
    {
        //延迟标记向下传递
        add[rt<<1] += add[rt];
        add[rt<<1|1] += add[rt];
        //更新子节点的值
        se[rt<<1] += add[rt]*(ll)(Mid-l+1);
        se[rt<<1|1] += add[rt]*(ll)(r-Mid);
        //清空当前标识
        add[rt] = 0;
    }
}

void build(int rt, int l, int r)
{
    add[rt] = 0;    // 延迟标记
    if(l == r)
        scanf("%lld",&se[rt]);
    else
    {
        build(lson);
        build(rson);
        pushUp(rt);
    }
}

ll query(int rt, int l, int r, int L, int R)   //从l,r 中查询 L,R
{
    if(L<= l && r <= R)
        return se[rt];
    else
    {
        if(add[rt])
            pushDown(rt,l,r);
        ll tmp = 0;
        if(L <= Mid)
            tmp += query(lson,L,R);
        if(R > Mid)
            tmp += query(rson,L,R);
        return tmp;
    }
}

void update(int rt, int l, int r, int L, int R, ll val)
{
    if(L<=l && r<=R)
    {
        add[rt] += val;
        se[rt] += (ll)(r-l+1)*val;
    }
    else
    {
        if(add[rt])
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
    int n,q;
    while(~scanf("%d %d",&n,&q))
    {
        build(1,1,n);
        char op[10];
        int L,R;
        ll va;
        while(q--)
        {
            scanf("%s",op);
            if(op[0] == 'Q')
            {
                scanf("%d %d",&L,&R);
                printf("%lld\n",query(1,1,n,L,R));
            }
            else
            {
                scanf("%d %d %lld",&L,&R,&va);
                update(1,1,n,L,R,va);
            }
        }
    }
    return 0;
}
