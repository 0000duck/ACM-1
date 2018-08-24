#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a,b;
int main()
{
    ll ans;
    while(~scanf("%I64d %I64d %I64d %I64d",&n,&m,&a,&b))
    {
        if(n%m==0)
            ans=0;
        else
        {
            if(n < m)   //少就全拆加到m
                ans = min(n*b,(m-n)*a);
            if(n > m)
            {
                ll cha = n%m;
                ans = cha*b;
                ans = min(ans,(m-cha)*a);
            }
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
