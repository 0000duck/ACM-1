#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<cstring>
using namespace std;
const int INF = 1e9+10;
const int maxn = 1e5+10;
const double PI = 3.1415926;
struct point{
    int x,y;
}p[maxn];

int stack[maxn],top;

//叉积  (p1-p0)x(p2-p0)   A*B*Sin(x)   p0p1 x p0p2 判断p2的位置
double xmult(point p0,point p1, point p2)
{
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}

double dist(point a, point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

bool cmp(point a, point b)  //极角排序
{
    int tmp = xmult(p[0],a,b);
    if(tmp>0)
        return true;
    else if(tmp==0 && dist(p[0],a) < dist(p[0],b))
        return true;
    else
        return false;
}

bool cmp1(point a, point b)
{
    if( a.y < b.y)
        return true;
    else if(a.y == b.y)
        return a.x<b.x;
    else
        return false;
}

void Graham(int n)
{
    int i;
    if(n<=2)
    {
        for(int i=0; i<n; i++)
            stack[i] = i;
        top=n-1;
    }
    else
    {
        top=1;
        stack[0] = 0;
        stack[1] = 1;
        for(int i=2; i<n; i++)
        {
            while(top>0 && xmult(p[stack[top-1]],p[stack[top]],p[i])<=0 )
                top--;
            stack[++top]=i;
        }
    }
}

int main()
{
    int N,L;
    while(~scanf("%d%d",&N,&L))
    {
        int low=0;
        for(int i=0; i<N; i++)
        {
            scanf("%d %d",&p[i].x,&p[i].y);
            if(p[low].y == p[i].y && p[low].x > p[i].x || p[low].y > p[i].y)
                low = i;
        }
        swap(p[0],p[low]);
        sort(p+1,p+N,cmp);
        Graham(N);

        double res = 0;
        for(int i=0; i<top; i++)
            res += dist(p[stack[i]],p[stack[i+1]]);
        res += dist(p[stack[0]],p[stack[top]]);
        res += 2*PI*L;
        printf("%d\n",(int)(res+0.5));
    }
}
