#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;
#define ll long long
#define INF 1e10
int X[maxn],P[maxn],C[maxn];
ll sumxp[maxn],sump[maxn],f[maxn];
typedef pair<ll,ll> point;
point q[maxn];
int r,h;

inline int read() {
    char c=getchar(); int x=0,f=1;
    while(c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9') {x=x*10+c-'0';c=getchar();}
    return x*f;
}

double slop(point x, point y)
{
    if(x.first == y.first)
        return x.second < y.second? INF:-INF;
    return (double)(x.second-y.second)/(x.first-y.first);
}

void Insert(point x)
{
    while(r-h > 1)
    {
        if( slop(q[r],x) < slop(q[r-1],q[r]))
            r--;
            //q[r--] = q[0];
        else
            break;
    }
    q[++r] = x;
}

point getans(double s)
{
    while(r-h>1)
    {
        if(slop(q[h+1],q[h+2]) < s)
            h++;
            //q[++h] = q[0];
        else
            break;
    }
    return q[h+1];
}


int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        X[i] = read();
        P[i] = read();
        C[i] = read();
    }
    for(int i=1; i<=n; i++)
    {
        sumxp[i] = sumxp[i-1] + (ll)X[i]*P[i];
        sump[i] = sump[i-1] + P[i];
    }
    for(int i=1; i<=n; i++)
    {
        Insert( make_pair(sump[i-1], f[i-1]+sumxp[i-1]));
        point p = getans(X[i]);
        f[i] = p.second + X[i]*sump[i] - X[i]*p.first - sumxp[i] + C[i];
    }
    cout<<f[n]<<endl;
    return 0;
}
