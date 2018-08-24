#include<bits/stdc++.h>
using namespace std;
long long cnt(long long n)
{
    long long x=1;
    while(n>1)
    {
        x=x*2+1;
        n/=2;
    }
    return x;
}

long long query(long long n,long long l,long long r,long long L,long long R)
{
    if(r<L || l>R || n==0)
        return 0;
    if(n==1)
        return 1;
    long long m = (L+R)/2;
    return query(n/2,l,r,L,m-1)+query(n%2,l,r,m,m)+query(n/2,l,r,m+1,R);
}

int main()
{
    long long n,l,r;
    while(~scanf("%lld %lld %lld",&n,&l,&r))
    {
        long long len = cnt(n);
        printf("%lld\n",query(n,l,r,1,len));
    }
    return 0;
}


