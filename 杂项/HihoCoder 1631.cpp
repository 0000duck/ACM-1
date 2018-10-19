#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 200;
int m,n,x;
int c[maxn];
int a[maxn];

int main()
{
    while(~scanf("%d %d %d",&m,&n,&x))
    {
        for(int i=1; i<=n; i++)
            scanf("%d",&c[i]);
        int tol = m, rem = 0;
        sort(c+1,c+1+n);
        for(int i=0; i<=x; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(i==0)
                {
                    if(tol>0)
                    {
                        a[j] = c[j];
                        --tol;
                    }
                    continue;
                }
                if(a[j] > 0)
                {
                    a[j]--;
                    if(a[j]==0 && tol > 0)
                    {
                        a[j] = c[j];
                        tol--;
                    }
                }
            }
        }
        int ans1=tol, ans2=0;
        for(int i=1; i<=n; i++)
        {
            if(c[i]==a[i])
                ans1++;
            else if(a[i] > 0)
                ans2++;
        }
        printf("%d %d\n",ans1,ans2);
    }
}
