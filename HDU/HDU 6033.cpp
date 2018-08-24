#include<bits/stdc++.h>
using namespace std;

int main()
{
    int m;
    int T=1;
    while(~scanf("%d",&m))
    {
        int ans = m/log2(10);
        printf("Case #%d: %d\n",T++,ans);
    }
    return 0;
}
