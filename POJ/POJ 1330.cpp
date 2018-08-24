#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
const int maxn = 1e5+10;

int par[maxn];
int n;
set<int> s;

void init()
{
    s.clear();
    for(int i=0; i<maxn; i++)
        par[i] = i;
}
/*
4
1 2
1 3
3 4
*/
int findd(int x, int y)
{
    while(x != par[x])
    {
        s.insert(x);
        x = par[x];
    }
    while(y != par[y])
    {
        if(s.find(y) != s.end())
            return y;
        else
            s.insert(y);
        y = par[y];
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        init();
        int father,son;
        for(int i=1; i<n; i++)
        {
            scanf("%d %d",&father,&son);
            par[son] = father;
        }
        int x,y;
        scanf("%d %d",&x,&y);
        int ans = 0;
        ans = findd(x,y);
        printf("%d\n",ans);
    }
    return 0;
}
