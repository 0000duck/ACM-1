#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
#define TYPE int

const int maxn = 1e5+10;
struct point{
    TYPE x,y;
}p[maxn];

int s[maxn],top;

//叉积  (p1-p0)x(p2-p0)   A*B*Sin(x)   p0p1 x p0p2 判断p2的位置
TYPE xmult(point p0,point p1, point p2)
{
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}

TYPE dist(point a, point b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

bool cmp(point a, point b)  //极角排序  y最小 且x最小的点作为极点  逆时针扫描其他点并排序
{
    int tmp = xmult(p[0],a,b);
    if(tmp>0)
        return true;
    else if(tmp==0 && dist(p[0],a) < dist(p[0],b))
        return true;
    else
        return false;
}

void Graham(int n)	//结果存于 stack
{
    if(n<=2)
    {
        for(int i=0; i<n; i++)
            s[i] = i;
        top=n-1;
    }
    else
    {
        top=1;
        s[0] = 0;
        s[1] = 1;
        for(int i=2; i<n; i++)
        {
            while(top>0 && xmult(p[s[top-1]],p[s[top]],p[i]) <= 0 )
                top--;
            s[++top]=i;
        }
    }
    top++;
}

TYPE RC()   //旋转卡壳
{
    int q,ans = 0;
     q = 1;
     ans = dist(p[s[0]],p[s[1]]);
     for(int i = 0; i != top ;i ++)
     {
           while(abs(xmult(p[s[(i+1)%top]],p[s[i%top]],p[s[(q+1)%top]])) > abs(xmult(p[s[(i+1)%top]],p[s[i%top]],p[s[q%top]]))) q = (q + 1)%top;
             ans = max(ans , max(dist(p[s[(i+1)%top]],p[s[q]]),dist(p[s[i%top]],p[s[q]])));
     }
     printf("%d\n",ans);
}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=0; i<n; i++)
            scanf("%d %d",&p[i].x,&p[i].y);
        int low = 0;
        for(int i=1; i<n; i++)
            if(p[low].y == p[i].y && p[low].x > p[i].x || p[low].y > p[i].y)
                low = i;
        if(low)
            swap(p[0],p[low]);
        sort(p+1,p+n,cmp);
        Graham(n);
        RC();
    }
    return 0;
}
