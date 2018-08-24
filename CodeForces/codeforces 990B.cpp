#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e6 +10;
int n,k;
int a[maxn];
int pre[maxn];
int main()
{
    while(~scanf("%d %d",&n,&k))
    {
        memset(pre,0,sizeof(pre));
        for(int i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
            pre[a[i]]++;
        }
        for(int i=1; i<maxn; i++)
            pre[i] += pre[i-1];
        sort(a,a+n);
        int ans = n;
        for(int i=0; i<n; i++)
        {
            if(a[i]+k < maxn && pre[a[i]+k] - pre[a[i]] > 0)
                ans--;
        }
        printf("%d\n",ans);
    }
}
