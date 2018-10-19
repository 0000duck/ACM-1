#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;

struct node{
    int ls,rs, sum;

} ns [maxn*20];

int ct; //记录现有的线段树数目
int rt[maxn*20]; //第i个线段树的根节点

void cpy(int& now, int old){
    now = ++ct;
    ns[now] = ns[old];
}

void pushUp(int& now)
{
    ns[now].sum = ns[ns[now].ls].sum + ns[ns[now].rs].sum;
}

void build(int& now, int l, int r)
{
    now = ++ct;
    ns[now].sum = 0;
    if(l==r) return;
    int m = (l+r)>>1;
    build(ns[now].ls,l,m);
    build(ns[now].rs,m+1,r);
}

void update(int& now, int old, int l, int r, int x)
{
    cpy(now, old);
    if(l==r){
        ns[now].sum++;
        return;
    }
    int m = (l+r)>>1;
    if(x<=m)
        update(ns[now].ls, ns[old].ls, l, m, x);
    else
        update(ns[now].rs, ns[old].rs, m+1, r, x);
    pushUp(now);
}

int query(int s, int t, int l, int r, int k)
{
    if(l == r) return l;
    int m =(l+r) >> 1;
    int cnt = ns[ns[t].ls].sum - ns[ns[s].ls].sum;
    if(k <= cnt)
        return query(ns[s].ls, ns[t].ls, l ,m, k);
    return query(ns[s].rs,ns[t].rs, m+1, r, k-cnt);
}

void init(int n)
{
    ct = 0;
    build(rt[0],1,n);
}

int a[maxn],b[maxn];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1; i<=n; i++){
            scanf("%d",&a[i]);
            b[i] = a[i];
        }
        sort(b+1,b+n+1);
        int sz = unique(b+1,b+1+n)-b-1;
        init(sz);
        for(int i=1; i<=n; i++){
            a[i] = lower_bound(b+1, b+1+sz, a[i]) -b;
            update(rt[i],rt[i-1],1,sz,a[i]);
        }
        while(m--){
            int s,t,k;
            scanf("%d%d%d",&s,&t,&k);
            printf("%d\n",b[query(rt[s-1],rt[t],1,sz,k)]);
        }
    }
}
