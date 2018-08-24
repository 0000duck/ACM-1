#include<bits/stdc++.h>
using namespace std;

deque<int> q;
map<int,int> m;
int main()
{
    long long n,k;
    while(~scanf("%lld %lld",&n,&k))
    {
        q.clear();
        for(int i=0; i<n; i++)
        {
            int t;
            scanf("%d",&t);
            q.push_back(t);
        }
        for(int i=0; i<n; i++)
        {
            int a = q.front();
            q.pop_front();
            int b = q.front();
            q.pop_front();
            if(a<b)
            {
                q.push_back(a);
                q.push_front(b);
                m[b]++;
                if(m[b]==k)
                {
                    printf("%d\n",b);
                    return 0;
                }
            }
            else
            {
                q.push_back(b);
                q.push_front(a);
                m[a]++;
                if(m[a]==k)
                {
                    printf("%d\n",a);
                    return 0;
                }
            }
        }
        printf("%d\n",q.front());
    }
    return 0;
}
