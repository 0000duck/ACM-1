#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
int a[MAXN];
int laz[MAXN];
int main()
{
	int N;
	while(~scanf("%d",&N) && N)
	{
		memset(laz,0,sizeof(laz));
		for (int i = 1; i <= N; ++i)
		{
			int l,r;
			scanf("%d %d",&l,&r);
			++laz[l];
			--laz[r+1];
		}
		memset(a,0,sizeof(a));
		int add = 0;
		for (int i = 1; i <= N; ++i)
		{
			add += laz[i];
			if(i==N)
				printf("%d\n",add);
			else
				printf("%d ",add);
		}
	}
	return 0;
}
