#include<cstdio>
#include<algorithm>
using namespace std;
int num[100010];
int dp[100010]; //dp[i] 代表以i为终点的最大子序列的和

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int tt = 1;
        int N;
        scanf("%d",&N);
        for(int i=0; i<N; i++)
        {
            scanf("%d",&num[i]);
            dp[i] = -2000;
        }
        dp[0] = num[0];
        for(int i=1; i<N; i++)
            dp[i] = max(num[i],dp[i-1]+num[i]);
        int ans = -2000;
        int ll, rr;
        for(int i=0; i<N; i++)
        {
            if(ans < dp[i])
            {
                ans = dp[i];
                rr = i;
            }
        }
        int temp = ans;
        for(int i = rr; i>=0; i--)
        {
            temp-=num[i];
            if(temp==0)
                ll = i;
        }
        printf("Case %d:\n",tt++);
        printf("%d %d %d\n\n",ans,++ll,++rr);
    }
}
