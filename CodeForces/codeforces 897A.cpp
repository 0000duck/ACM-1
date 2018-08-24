#include<bits/stdc++.h>
using namespace std;

char a[120];
int main(int argc, char const *argv[])
{
	int n,m;
	while(~scanf("%d %d",&n,&m))
	{
		scanf("%s",a);
		int l,r;
		char c1,c2;
		for(int i=0; i<m; i++)
		{
			scanf("%d %d %c %c",&l,&r,&c1,&c2);
			for(int j=l-1; j<r; j++)
			{
				if(a[j] == c1)
					a[j] = c2;
			}
		}
		printf("%s\n",a);
	}
	return 0;
}