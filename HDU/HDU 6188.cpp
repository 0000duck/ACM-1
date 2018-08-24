#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e6+10;

int a[maxn];
int n;
int main()
{
    while(~scanf("%d",&n))
    {
        int tmp;
        memset(a,0,sizeof(a));
        for(int i=0; i<n; i++)
        {
            scanf("%d",&tmp);
            a[tmp]++;
        }
        int ans=0;
        for(int i=1; i<=n; i++)
        {
            if(a[i]>=2)
            {
                ans+=(a[i]/2);
                a[i]%=2;
            }
            if(a[i]==1 && a[i+1]%2==1 && a[i+2])
            {
                ans++;
                a[i]--;
                a[i+1]--;
                a[i+2]--;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
