#include<cstdio>
#include<algorithm>
using namespace std;

#define Mid ((l+r)>>1)
#define lson rt<<1,l,Mid
#define rson rt<<1|1,Mid+1,r

const int MAX = 50010;
int n,q;
int maxCow[MAX<<2];
int minCow[MAX<<2];
int a[MAX];

void pushUp(int rt)
{
    maxCow[rt] = max(maxCow[rt<<1],maxCow[rt<<1|1]);
    minCow[rt] = min(minCow[rt<<1],minCow[rt<<1|1]);
}

void build(int rt, int l, int r)
{
    if(l == r)
    {
        scanf("%d",&maxCow[rt]);
        minCow[rt] = maxCow[rt];
    }
    else
    {
        build(lson);
        build(rson);
        pushUp(rt);
    }
}

int queryMax(int rt, int l, int r, int L, int R)
{
    if(L <= l && r <= R)
        return maxCow[rt];
    int tmp = -1;
    if(L <= Mid)
        tmp = max(queryMax(lson,L,R),tmp);
    if(R > Mid)
        tmp = max(queryMax(rson,L,R),tmp);
    return tmp;
}

int queryMin(int rt, int l, int r, int L, int R)
{
    if(L <= l && r <= R)
        return minCow[rt];
    int tmp = 1e9;
    if(L <= Mid)
        tmp = min(queryMin(lson,L,R),tmp);
    if(R > Mid)
        tmp = min(queryMin(rson,L,R),tmp);
    return tmp;
}

int main()
{
    while(~scanf("%d %d",&n,&q))
    {
        build(1,1,n);
        int l,r;
        for(int i=0; i<q; i++)
        {
            scanf("%d %d",&l,&r);
            printf("%d\n",queryMax(1,1,n,l,r)-queryMin(1,1,n,l,r));
        }
    }
    return 0;
}
