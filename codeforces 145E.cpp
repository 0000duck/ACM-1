#include<bits/stdc++.h>
#define Mid ((l+r)>>1)
#define lson (rt<<1)+1,l,Mid
#define rson (rt<<1)+2,Mid+1,r
#define ll (rt<<1)+1
#define rr (rt<<1)+2
using namespace std;
const int MAX = 1000010;
char str[MAX];

struct Tree{
    int num4;
    int num7;
    int down;
    int rise;
}seg[(MAX<<2)+1];
int swi[(MAX<<2)+1];

void pushup(int rt)
{
    seg[rt].num4 = seg[ll].num4 + seg[rr].num4;
    seg[rt].num7 = seg[ll].num7 + seg[rr].num7;
    seg[rt].down = max(seg[ll].num7 + seg[rr].down, seg[ll].down + seg[rr].num4);
    seg[rt].rise = max(seg[ll].num4 + seg[rr].rise, seg[ll].rise + seg[rr].num7);
}

void build(int rt, int l, int r)
{
    swi[rt] = 0;
    if(l == r)
    {
        if(str[l] == '4')
        {
            seg[rt].num4=seg[rt].rise=seg[rt].down = 1;
            seg[rt].num7=0;
            return ;
        }
        else
        {
            seg[rt].num7=seg[rt].rise=seg[rt].down=1;
            seg[rt].num4 = 0;
            return ;
        }
    }
    else
    {
        build(lson);
        build(rson);
        pushup(rt);
    }
}

void pushDown(int rt)
{
    if(swi[rt] != 0)
    {
        swi[ll] += swi[rt];
        swi[rr] += swi[rt];
        if(swi[rt]&1)
        {
            swap(seg[ll].num4,seg[ll].num7);
            swap(seg[ll].rise,seg[ll].down);
            swap(seg[rr].num4,seg[rr].num7);
            swap(seg[rr].rise,seg[rr].down);
        }
        swi[rt] = 0;
    }
}

void update(int rt, int l, int r, int L, int R)
{
    if(L <= l && R >= r)
    {
        swi[rt] += 1;
        swap(seg[rt].num4,seg[rt].num7);
        swap(seg[rt].rise,seg[rt].down);
    }
    else
    {
        pushDown(rt);
        if(L <= Mid)
            update(lson,L,R);
        if(R > Mid)
            update(rson,L,R);
        pushup(rt);
    }
}

int query(int rt, int l, int r, int L, int R)
{
    if(L<=l && r <=R)
    {
        return seg[rt].rise;
    }
    else
    {
        pushDown(rt);
        if(L<=Mid)
            return query(lson,L,R);
        if(R>Mid)
            return query(rson,L,R);
    }
}

int main()
{
    int n,m;
    while(~scanf("%d %d",&n,&m))
    {
        scanf("%s",str);
        //memset(swi,0,sizeof(swi));
        build(0,0,n-1);
        char input[10];
        int l,r;
        for(int i=0; i<m; i++)
        {
            scanf("%s",input);
            if(input[0] == 's')
            {
                scanf("%d %d",&l,&r);
                update(0,0,n-1,l-1,r-1);
            }
            else
            {
                printf("%d\n",seg[0].rise);
            }
        }
    }
    return 0;
}
