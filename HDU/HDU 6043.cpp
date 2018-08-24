#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k;
int T;

int main()
{
    T = 1;
    while(~scanf("%lld %lld",&n,&k))
    {
        printf("Case #%d: ",T++);
        if(k<=n)
            printf("%lld\n",k);
        else
        {
            k-=n;
            ll check = k%(n-1);
            ll time = k/(n-1);
            if(check == 0)
            {
                if(time%2)
                    printf("%lld\n",n-1);
                else
                    printf("%lld\n",n);
            }
            else
                printf("%lld\n",check);
        }
    }
    return 0;
}
