#include <cstdio>
#include <cmath>
#include <iostream>
#define Mid ((l+r)>>1)
#define lson rt<<1,l,Mid
#define rson rt<<1|1,Mid+1,r

using namespace std;

const int MAX = 200000+5;
int seg[MAX<<2];

void build(int rt, int l, int r)
{
    if(l==r)
        scanf("%d",&seg[rt]);
    else
    {
        build(lson);
        build(rson);
        seg[rt] = max(seg[rt<<1] , seg[rt<<1|1]);
    }
}

void update(int rt, int l, int r, int pos, int num)
{
    if(l == r && r == pos)
        seg[rt] = num;
    else
    {
        if(pos <= Mid)
            update(lson,pos,num);
        if(pos > Mid)
            update(rson,pos,num);
        seg[rt] = max(seg[rt<<1], seg[rt<<1|1]);
    }
}

int query(int rt, int l, int r, int L, int R)
{
    if(L <= l && r <= R)
        return seg[rt];
    else
    {
        int tmp = -1;
        if(L <= Mid)
            tmp = max(tmp,query(lson,L,R));
        if(R > Mid)
            tmp = max(tmp,query(rson,L,R));
        return tmp;
    }
}

int main()
{
    int n,m,L,R;
    char oper[10];
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        build(1,1,n);
        getchar();
        while(m--)
        {
            scanf("%s%d%d",oper,&L,&R);
            if(oper[0] == 'Q')
                printf("%d\n",query(1,1,n,L,R));
            else
                update(1,1,n,L,R);
        }
    }
    return 0;
}
}
