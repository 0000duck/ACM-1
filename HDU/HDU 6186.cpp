#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5+10;
ll preAnd[maxn],taiAnd[maxn];
ll preOr[maxn],taiOr[maxn];
ll Xor;
ll a[maxn];
int n,q;

int main()
{
    while(~scanf("%d %d",&n,&q))
    {
        for(int i=1; i<=n; i++)
        {
            scanf("%lld",&a[i]);
            if(i==1)
                Xor = preAnd[i] = preOr[i] = a[i];
            else
            {
                preAnd[i] = preAnd[i-1]&a[i];
                preOr[i] = preOr[i-1]|a[i];
                Xor ^= a[i];
            }
        }
        for(int i=n; i>=1; i--)
        {
            if(i==n)
                taiAnd[i] = taiOr[i] = a[i];
            else
            {
                taiAnd[i] = taiAnd[i+1]&a[i];
                taiOr[i] = taiOr[i+1]|a[i];
            }
        }
        int tmp;
        int ansAnd,ansOr,ansXor;
        while(q--)
        {
            scanf("%d",&tmp);
            if(tmp == 1)
            {
                ansAnd = taiAnd[tmp+1];
                ansOr = taiOr[tmp+1];
                ansXor = Xor^a[tmp];
            }
            else if(tmp == n)
            {
                ansAnd = preAnd[tmp-1];
                ansOr = preOr[tmp-1];
                ansXor = Xor^a[tmp];
            }
            else
            {
                ansAnd = preAnd[tmp-1]&taiAnd[tmp+1];
                ansOr = preOr[tmp-1]|taiOr[tmp+1];
                ansXor = Xor^a[tmp];
            }
            printf("%lld %lld %lld\n",ansAnd,ansOr,ansXor);
        }
    }
}
