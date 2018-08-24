#include<set>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;

#define Mid ((l+r)>>1)
#define lson rt<<1,l,Mid
#define rson rt<<1|1,Mid+1,r
#define ll long long
const int MAX = 20010;

int inputl[10010],inputr[10010];
int n,en;

struct temp{
    int val;
    int id;
    int lr;
};

struct node{
    int color;
}tree[MAX<<2];

vector<temp> v;
set<int> c;
bool cmp(temp a,temp b)
{
    return a.val < b.val;
}

void init()
{
    v.clear();
    c.clear();
    scanf("%d",&n);
    int tmp1,tmp2;
    temp tmp;
    for(int i=1; i<=n; i++)
    {
        tmp.id = i;
        scanf("%d %d",&tmp1,&tmp2);
        tmp.val = tmp1;
        tmp.lr = 0;
        v.push_back(tmp);
        tmp.val = tmp2;
        tmp.lr = 1;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end(),cmp);
    int idx = 1;
    if(v[0].lr)
        inputr[v[0].id] = idx;
    else
        inputl[v[0].id] = idx;
    for(int i=1; i<v.size(); i++)
    {
        if(v[i].val != v[i-1].val)
            idx++;
        if(v[i].lr)
            inputr[v[i].id] = idx;
        else
            inputl[v[i].id] = idx;
    }
    en = idx;
}

void build(int rt, int l, int r)
{
    tree[rt].color = 0;
    if(l==r)
        return;
    build(lson);
    build(rson);
}

void pushDown(int rt)
{
    tree[rt<<1].color = tree[rt<<1|1].color = tree[rt].color;
    tree[rt].color = 0;
}

void update(int rt, int l, int r, int L, int R, int color)
{
    if(L<=l && r<=R)
    {
        tree[rt].color = color;
        return ;
    }
    if(tree[rt].color!=0)
        pushDown(rt);
    if(L <= Mid)
        update(lson,L,R,color);
    if(R > Mid)
        update(rson,L,R,color);
}

void query(int rt, int l, int r)
{
    if(tree[rt].color != 0 && c.find(tree[rt].color)==c.end())
    {
        c.insert(tree[rt].color);
        return;
    }
    if(l==r)
        return;
    if(tree[rt].color!=0)
        pushDown(rt);
    query(lson);
    query(rson);
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        init();
        build(1,1,en);
        for(int i=1; i<=n; i++)
            update(1,1,en,inputl[i],inputr[i],i);
        query(1,1,en);
        printf("%d\n",c.size());
    }
}
