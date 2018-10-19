#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
#define ll long long
const int maxn = 2e5+100;
struct point
{
    ll x,y;
} p[maxn];

int s[maxn],top;

//叉积  (p1-p0)x(p2-p0)   A*B*Sin(x)   p0p1 x p0p2 判断p2的位置
ll xmult(point p0,point p1, point p2)
{
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}

double pow2(double x){
    return x*x;
}

double dist(point a, point b)
{
    return sqrt(pow2(a.x-b.x)+pow2(a.y-b.y));
}

double len(point a,  point b , point c)
{
    double tmp = fabs(xmult(a,b,c));
    return tmp/dist(b,c);
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

double RC()   //旋转卡壳
{
    if(top<=2) return 0;
    int q = 1 ;
    double ans = 9e18;
    for(int i = 0; i != top ; i ++)
    {
        //凸包宽度
        while(fabs(xmult(p[s[i%top]],p[s[(i+1)%top]],p[s[(q+1)%top]])) > fabs(xmult(p[s[i%top]],p[s[(i+1)%top]],p[s[q%top]])))
            q = (q + 1)%top;
        ans = min(ans, len(p[s[q%top]],p[s[i%top]],p[s[(i+1)%top]]));
    }
    return ans;
}
int main()
{
    int n,r;
    scanf("%d %d",&n,&r);
    for(int i=0; i<n; i++)
        scanf("%I64d %I64d",&p[i].x,&p[i].y);
    int low = 0;
    for(int i=1; i<n; i++)
        if(p[low].y == p[i].y && p[low].x > p[i].x || p[low].y > p[i].y)
            low = i;
    swap(p[0],p[low]);
    sort(p+1,p+n,cmp);
    Graham(n);
    printf("%.16f",RC());
    return 0;
}
