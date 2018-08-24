#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b;
    int x,y;
    while(~scanf("%d %d",&a,&b))
    {
        int gcd = __gcd(a,b);
        int delta = a*a - 4*b*gcd;
        if( delta < 0 )
            printf("No Solution\n");
        else if((int)sqrt(delta)*(int)sqrt(delta) != delta)
            printf("No Solution\n");
        else if((a+(int)sqrt(delta))%2 != 0)
            printf("No Solution\n");
        else
        {
            x = (a - sqrt(delta))/2;
            y = a-x;
            if(x>0 && y>0)
                printf("%d %d\n",x,y);
            else
            {
                x = (a + sqrt(delta))/2;
                y = a-x;
                if(x>0 && y>0)
                    printf("%d %d\n",x,y);
                else
                    printf("No Solution\n");
            }
        }
    }
    return 0;
}
