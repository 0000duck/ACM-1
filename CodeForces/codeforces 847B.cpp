#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
deque<int> que[maxn];
int len;

int binary_s(int n)
{
    int l=0,r=len,m;
    while(l<r)
    {
        m=(l+r)/2;
        if(*que[m].rbegin()<=n)
            r = m;
        else
            l = m + 1;
    }
    if(r==len)
        return -1;
    return r;

}

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int t;
        len=0;
        for(int i=0; i<n; i++)
        {
            scanf("%d",&t);
            int res = binary_s(t);
            if(res == -1)
                que[len++].push_back(t);
            else
                que[res].push_back(t);
        }
        for(int i=0; i<len; i++)
        {
            printf("%d",que[i].front());
            que[i].pop_front();
            while(!que[i].empty())
            {
                printf(" %d",que[i].front());
                que[i].pop_front();
            }
            printf("\n");
        }
    }

    return 0;
}
