#include<bits/stdc++.h>
using namespace std;

int n,k,m;
map<string,int> mm;

int val[100010];
int temp[100010];


int main()
{
    while(~scanf("%d %d %d",&n,&k,&m))
    {
        string t;
        for(int i=1; i<=n; i++)
        {
            cin>>t;
            mm.insert( pair<string,int>(t,i) );
        }
        for(int i=1; i<=n; i++)
            scanf("%d",&val[i]);
        for(int i=1; i<=k; i++)
        {
            int x;
            scanf("%d",&x);
            priority_queue<int> q;
            for(int k=0; k<x; k++)
            {
                scanf("%d",&temp[k]);
                q.push(-val[temp[k]]);
            }
            int mmin = -q.top();
            for(int k=0; k<x; k++)
                val[temp[k]] = mmin;
        }
        long long ans = 0;
        for(int i=0; i<m; i++)
        {
            cin>>t;
            ans += val[mm[t]];
        }
        printf("%lld\n",ans);
    }
    return 0;
}
