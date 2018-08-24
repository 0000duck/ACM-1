#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a,b,c,d;

void solve()
{
    ll ans = 0;
    ll tmp;

    tmp = b/2018 - a/2018;
    ans += tmp*(d-c+1);
    printf("%d\n",tmp);

    tmp = d/2018 - c/2018;
    ans += tmp*(b-a+1);
    printf("%d\n",tmp);

    tmp = b/1009 - a/1009;
    ans += tmp*(d/2 - c/2);
    printf("%d\n",tmp);

    tmp = d/1009 - c/1009;
    ans += tmp*(b/2 - a/2);
    printf("%d\n",tmp);
    cout<<ans<<endl;
}
int main()
{

    while(~scanf("%d %d %d %d",&a,&b,&c,&d))
    {
        for(int i=1; i<=10000; i++)
            for(int j=1; j<=10000; j++)
                if(i*j%2018 == 0)
                    printf("%d %d\n",i,j);
        //solve();
    }
    return 0;
}
