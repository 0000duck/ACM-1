#include<bits/stdc++.h>
using namespace std;
const double PI = 4.*atan(1.);
int main()
{
    int T;
    int a,b;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&a,&b);
        double ans = a*PI + 2*b - 0.0000005;
        printf("%.6lf\n",ans);
    }
    return 0;
}
