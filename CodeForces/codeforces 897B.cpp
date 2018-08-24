#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll get_length(ll x)
{
    int leng=0;
    while(x)
    {
        x/=10;
        leng++;
    }
    return leng;
}

ll getZcyNum(ll x)
{
	ll tmp=x,res=0;
	ll l = get_length(x);
	while(l>0)
	{
		x*=10;
		l--;
	}
    while(tmp)
    {
        res=res*10+tmp%10;
        tmp=tmp/10;
    }
    return x+res;
}



int main()
{
	ll k,p;
	while(~scanf("%lld %lld",&k,&p))
	{
		long long sum = 0;
		for(int i = 1; i<=k; i++)
		{
			sum+= getZcyNum(i);
			sum%=p;
		}
		printf("%lld\n",sum%p);
	}
	return 0;
}
