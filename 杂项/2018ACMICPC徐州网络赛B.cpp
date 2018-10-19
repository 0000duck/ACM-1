#include<bits/stdc++.h>
using namespace std;
#define BE -1
#define GE 1
#define NE 0
int n,m,k,l;
int tol[1100][3];
int dp[1100][200]; //+100偏移量  dp[i][j]代表在第i轮 分数为j时的状态
const int mov = 100;

int check(int x)
{
    if(x>200)
        return 200;
    else if(x<0)
        return 0;
    else
        return x;
}

void init()
{
    for(int j=-100; j<=100; j++)
    {
        if(j<=l)
            dp[n+1][j+mov] = BE;
        else if(j>=k)
            dp[n+1][j+mov] = GE;
        else
            dp[n+1][j+mov] = NE;
    }
}


int main()
{
    while(~scanf("%d%d%d%d",&n,&m,&k,&l))
    {
        for(int i=1; i<=n; i++)
            scanf("%d%d%d",&tol[i][0],&tol[i][1],&tol[i][2]);
        init();
        for(int i=n; i>=0; i--)
        {
            for(int j=-100; j<=100; j++)
            {
                int idx = j+mov;
                /// 当奇数轮时求最大值    偶数轮是求最小值
                int t1,t2,t3;
                if(i&1) ///奇数
                {
                    t1=t2=t3=-1;

                    if(tol[i][0] != 0)
                        t1 = dp[i+1][check(idx+tol[i][0])];
                    if(tol[i][1] != 0)
                        t2 = dp[i+1][check(idx-tol[i][1])];
                    if(tol[i][2] != 0)
                        t3 = dp[i+1][-j+mov];

                    dp[i][idx] = max(t1,max(t2,t3));
                }
                else
                {
                    t1=t2=t3=1;

                    if(tol[i][0] != 0)
                        t1 = dp[i+1][check(idx+tol[i][0])];
                    if(tol[i][1] != 0)
                        t2 = dp[i+1][check(idx-tol[i][1])];
                    if(tol[i][2] != 0)
                        t3 = dp[i+1][-j+mov];

                    dp[i][idx] = min(t1,min(t2,t3));
                }
            }
        }
        m+=100;
        if(dp[1][m] == NE)
            printf("Normal Ending\n");
        else if(dp[1][m] == GE)
            printf("Good Ending\n");
        else
            printf("Bad Ending\n");

    }
    return 0;
}
