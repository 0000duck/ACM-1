#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
const int maxn = 110;
int a[maxn];
int sum[maxn];
int dp[maxn][maxn][maxn]; //dp[i][j][k] 代表将区间[i,j]合并为k堆的最小花费
int n,L,R;


void init()
{
    memset(dp,INF,sizeof(dp));
    memset(sum,0,sizeof(sum));
    for(int i=1; i<=n ;i++)
    {
        for(int j=i; j<=n; j++)
        {
            dp[i][j][j-i+1] = 0;
        }
    }
}

int main()
{
    while(~scanf("%d%d%d",&n,&L,&R))
    {
        init();
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            if(i==1)
                sum[i] = a[i];
            else
                sum[i] = sum[i-1]+a[i];
        }

        for(int d=1; d<n; d++)
        {
            for(int i=1; i+d<=n; i++) //区间[i,i+d]
            {
                for(int p=0; p<d; p++)
                    for(int k=L; k<=R; k++)
                        dp[i][i+d][1] = min(dp[i][i+d][1], dp[i][i+p][k-1]+dp[i+p+1][i+d][1] + sum[i+d]-sum[i-1]);
                for(int k=2; k<=d; k++)
                    for(int p=0; p<d; p++)
                        dp[i][i+d][k] = min(dp[i][i+d][k], dp[i][i+p][k-1]+dp[i+p+1][i+d][1]);
            }
        }

        if(dp[1][n][1] == INF)
            cout<<"0"<<endl;
        else
            cout<<dp[1][n][1]<<endl;
    }
    return 0;
}
