#include<bits/stdc++.h>
using namespace std;

int a[100010];
long long pre[100010];
map<long long,int> aa;
map<long long,int> bb;
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        long long sum = 0;
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            sum += a[i];
            pre[i] = sum;
            bb[a[i]]++;
        }
        if(sum%2)
        {
            printf("NO\n");
            return 0;
        }
        for(int i=1; i<=n; i++)
        {
            if(pre[i] == sum/2)      //已经平分
            {
                printf("YES\n");
                return 0;
            }
            aa[a[i]]++;      // 1 ~ i 数集
            bb[a[i]]--;       // i+1 ~ n 数集
            long long x = abs(sum - 2*pre[i]);
            if( pre[i] > sum - pre[i] && aa[x/2]!=0)
            {
                printf("YES\n");
                return 0;
            }
            else if(pre[i] < sum - pre[i] && bb[x/2]!=0)
            {
                printf("YES\n");
                return 0;
            }
        }
        printf("NO\n");
        return 0;
    }
}
