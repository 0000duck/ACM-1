#include<cstdio>
#include<vector>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 110;
char in[maxn][maxn];
char ans[maxn][maxn];
int vis[maxn][maxn];
int N;
vector<char> v;

bool isout(int x, int y)
{
    if(  x<=N && x >=1 && y<=N && y>=1)
        return true;
    else
        return false;
}

void inser()
{
    memset(vis,0,sizeof(vis));
    int x=1, y=1,top=0;
    vis[x][y] = 1;
    ans[x][y] = v[top++];
    while(top < v.size())
    {
        while(isout(x,y+1) && !vis[x][y+1]) //右
        {
            y++;
            vis[x][y] = 1;
            ans[x][y] = v[top++];
            //cout<<top<<endl;
        }
        while(isout(x+1,y) && !vis[x+1][y]) //下
        {
            x++;
            vis[x][y] = 1;
            ans[x][y] = v[top++];
            //cout<<top<<endl;
        }
        while(isout(x,y-1) && !vis[x][y-1])  //左
        {
            y--;
            vis[x][y] = 1;
            ans[x][y] = v[top++];
            //cout<<top<<endl;
        }
        while(isout(x-1,y) && !vis[x-1][y]) //上
        {
            x--;
            vis[x][y] = 1;
            ans[x][y] = v[top++];
            //cout<<top<<endl;
        }
    }
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            printf("%c",ans[i][j]);
        }
        cout<<endl;
    }
}

int main()
{
    while(~scanf("%d",&N))
    {
        for(int i=1; i<=N; i++)
            scanf("%s",in[i]+1);
        v.clear();

        int x,y,flag;
        for(int i=1; i<=N; i++)
        {
            flag = i%2;     // 1从左下到右上   0从右上到左下
            x = 1;
            y = i;
            if(flag)
                swap(x,y);
            while(isout(x,y))
            {
                v.push_back(in[x][y]);
                if(flag)
                    x--, y++;
                else
                    x++, y--;
            }
        }
        for(int i=2; i<=N; i++)
        {
            flag = (i+N+1)%2;
            x = N;
            y = i;
            if(!flag)
                swap(x,y);
            while(isout(x,y))
            {
                v.push_back(in[x][y]);
                if(flag)
                    x--, y++;
                else
                    x++, y--;
            }
        }
        inser();
    }
    return 0;
}
