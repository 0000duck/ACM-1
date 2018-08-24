#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace  std;

const int maxN = 200010;
const int INFINITE = 1e9;
struct Tree
{
	int l,r;
	int max,min;
} tr[maxN<<2+1];

int a[maxN];
void build_tree(int root, int istart, int iend);
int query(int root, int qstart, int qend);

int main()
{
	int n,q;
	while(~scanf("%d %d",&n,&q))
	{
		for(int i=1; i<=n; i++)
			scanf("%d",&a[i]);
		build_tree(1,1,n);
		int l,r;
		for(int i=0; i<q; i++)
		{
			scanf("%d %d",&l,&r);
			printf("%d\n",query(1,l,r));
		}
	}
	return 0;
}

void build_tree(int root, int istart, int iend)
{
	tr[root].l = istart;
	tr[root].r = iend;
	if(istart == iend) //根节点
		tr[root].max = tr[root].min = a[istart];
	else
	{
		int mid = (istart + iend)/2;
		build_tree(root*2,istart,mid);	//左子树
		build_tree(root*2+1,mid+1,iend); //右子树
		//更新当前节点的值
		tr[root].max = max(tr[root*2].max,tr[root*2+1].max);
		tr[root].min = min(tr[root*2].min,tr[root*2+1].min);
	}
}

int query_tree_min(int root,int qstart,int qend)  //查询区间最小
{
	if(qstart > tr[root].r || qend < tr[root].l)	//查询区间和当前区间无交集
		return INFINITE;
	if(qstart <= tr[root].l && qend >= tr[root].r)	//查询区间包括当前查询区间
		return tr[root].min;
	int mid = (tr[root].l + tr[root].r) / 2;
	return min(query_tree_min(root*2,qstart,qend),
				query_tree_min(root*2+1,qstart,qend));
}

int query_tree_max(int root,int qstart,int qend)  //查询区间最大
{
	if(qstart > tr[root].r || qend < tr[root].l)
		return -1;
	if(qstart <= tr[root].l && qend >= tr[root].r)
		return tr[root].max;
	int mid = (tr[root].l + tr[root].r) / 2;
	return max(query_tree_max(root*2,qstart,qend),
				query_tree_max(root*2+1,qstart,qend));
}

int query(int root, int qstart, int qend)
{
	return query_tree_max(root,qstart,qend)-query_tree_min(root,qstart,qend);
}