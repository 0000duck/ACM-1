#include<bits/stdc++.h>
using namespace std;

bool vis[1100];
int col[1100];
int N,M,X,Y;
vector<int> vec[1100];
set<int> s;
int flag;
struct status{
    int node;
    int color;
};

void init()
{
    memset(vis,false,sizeof(vis));
    memset(col,-1,sizeof(col));
    for(int i=1; i<=N; i++)
        vec[i].clear();
    s.clear();
    flag = 1;
}

void dfs(int beg, int color)
{
    if(vis[beg])
        return;
    vis[beg] = true;
    col[beg] = color;
    for(int i=0; i<vec[beg].size(); i++)
    {
        if(!vis[ vec[beg][i] ])
            dfs(vec[beg][i],!color);
        else
            if(col[ vec[beg][i] ] == color)
                flag = 0;
    }
}

int main()
{
    while(~scanf("%d %d %d %d",&N,&M,&X,&Y))
    {
        int u,v;
        init();
        for(int i=0; i<M; i++)
        {
            scanf("%d %d",&u,&v);
            s.insert(u);
            s.insert(v);
            vec[u].push_back(v);
            vec[v].push_back(u);
        }
        set<int>::iterator ite;
        for(ite = s.begin(); ite != s.end(); ite++)
        {
            if(!vis[*ite])
                dfs(*ite,0);
        }
        int tmp;
        int rec = -1;
        for(int i=0; i<X; i++)
        {
            scanf("%d",&tmp);
            if(col[tmp] == -1)
                col[tmp] = 0;
            else if(rec == -1)
            {
                rec = col[tmp];
            }
            else
            {
                if( rec != col[tmp])
                    flag = 0;
            }
        }
        rec = -1;
        for(int i=0; i<Y; i++)
        {
            scanf("%d",&tmp);
            if(col[tmp] == -1)
                col[tmp] = 0;
            else if(rec == -1)
            {
                rec = col[tmp];
            }
            else
            {
                if( rec != col[tmp])
                    flag = 0;
            }
        }
        for(int i=1; i<=N; i++)
        {
            if(col[i] == -1)
                flag = 0;
            //printf("%d\n",col[i]);
        }
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");

    }
    return 0;
}
