#include<bits/stdc++.h>
using namespace std;


int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        long long n;
        scanf("%d",&n);
        if(n%3==0)
            printf("%lld\n",(n/3)*(n/3)*(n/3));
        else if(n%4==0)
        {
            long long x = n/4;
            printf("%lld\n",x*x*(n/2));
        }
        else
            printf("-1\n");
    }
    return 0;
}
