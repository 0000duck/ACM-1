#include<bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
int R;
double ans;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int m;
        scanf("%d %d",&m,&R);
        ans = 2*pi*R;
        for(int i=1; i<=m; i++)
        {
            double x,y,r,dis;
            scanf("%lf %lf %lf",&x,&y,&r);
            dis = sqrt(x*x + y*y);
            if(dis-r-R > 0)
                continue;
            else if(fabs(r-R)-dis > 0)
                continue;
            else if(R == r+dis)
                ans += 2*pi*r;
            else
                ans += 2*r*acos((r*r+dis*dis-R*R)/(2*r*dis)) - 2*R*acos((R*R+dis*dis-r*r)/(2*R*dis));
        }
        printf("%.12f\n",ans);
    }
    return 0;
}

