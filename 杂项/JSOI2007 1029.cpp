#include<bits/stdc++.h>
using namespace std;
struct rep
{
    int a;
    int b;
};
const int maxn = 150010;
rep t[maxn];
int tim;
int ans;
priority_queue<int> q;

bool cmp(rep x,rep y)
{
    if(x.b == y.b)
        return x.a<y.a;
    else
        return x.b<y.b;
}

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=1; i<=n; i++)
            scanf("%d %d",&t[i].a,&t[i].b);
        sort(t+1,t+n+1,cmp);
        tim = ans = 0;
        while(!q.empty())
            q.pop();
        for(int i=1; i<=n; i++)
        {
            if((tim + t[i].a) <= t[i].b)
            {
                ans++;
                tim = tim + t[i].a;
                q.push(t[i].a);
            }
            else
            {
                int k = q.top();
                if(k > t[i].a)
                {
                    q.pop();
                    q.push(t[i].a);
                    tim = tim - k + t[i].a;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
