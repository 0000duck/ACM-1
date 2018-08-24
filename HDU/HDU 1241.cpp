#include<cstdio>
#include<cstring>

const int MAX = 200;
char mm[MAX][MAX];
bool vis[MAX][MAX];
int dirx[8] = {0,1,1,1,0,-1,-1,-1};
int diry[8] = {-1,-1,0,1,1,1,0,-1};
//方向向量  对应八个方向
int m,n;

bool inmap(int x,int y) //判断坐标 x,y 是否在地图内
{
    if(x<0 || x>m-1 || y<0 || y>n-1)
        return false;
    return true;
}

void dfs(int x,int y)   //  DFS  扫描x,y八个方向的油田
{
    for(int i=0; i<8; i++)
    {
        int mx = x + dirx[i];
        int my = y + diry[i];
        if(inmap(x,y) && !vis[mx][my]  && mm[mx][my]=='@')  //如果这个点在地图内  没有访问过 并且是油田  就标记这个点 并且再次dfs
        {
            vis[mx][my] = true;
            dfs(mx,my);
        }
    }
}
int main()
{
    while(~scanf("%d %d",&m,&n))
    {
        if(m==0 && n==0)
            break;
        int ans = 0;
        memset(vis,false,sizeof(vis));  //初始化vis 为 false
        for(int i=0; i<m; i++)      //读入数据
            scanf("%s",mm[i]);

        for(int i=0; i<m; i++)  //  遍历这个地图
            for(int j=0; j<n; j++)
                if(!vis[i][j] && mm[i][j]=='@') //  如果没有访问过并且是油田  进行dfs
                {
                    ans++;
                    vis[i][j] = true;
                    dfs(i,j);
                }
        printf("%d\n",ans);
    }
}
