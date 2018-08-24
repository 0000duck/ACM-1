#include<bits/stdc++.h>
using namespace std;
const int MAXN = 8;
int chess[MAXN][MAXN];
int cnt = 0;

int in_chess(int x,int y)
{
    return (x<MAXN && x>=0 && y<MAXN && y>=0);
}

int check(int x,int y) //判断皇后放在位置x,y是否存在互吃
{
    int xx,yy;
    for(int i=0; i<MAXN; i++)
    {
        if(chess[x][i] || chess[i][y])  //对应行列
            return 0;
    }
    xx = x;
    yy = y;
    while(in_chess(xx,yy))
    {
        if(chess[xx++][yy++])
            return 0;
    }
    xx = x;
    yy = y;
    while(in_chess(xx,yy))
    {
        if(chess[xx--][yy--])
            return 0;
    }
    xx = x;
    yy = y;
    while(in_chess(xx,yy)) //  方向/
    {
        if(chess[xx++][yy--])
            return 0;
    }
    xx = x;
    yy = y;
    while(in_chess(xx,yy))
    {
        if(chess[xx--][yy++])
            return 0;
    }
    return 1;
}

void dfs(int q) //把第q个皇后放在第q行
{
    for(int i=0; i<MAXN; i++)
    {
        if(check(q,i))
        {
            if(q==MAXN-1)
            {
                cnt++;
            }
            else
            {
                chess[q][i] = 1;
                dfs(q+1);
                chess[q][i] = 0;
            }
        }
    }
}


int main()
{
    memset(chess,0,sizeof(chess));
    dfs(0);
    printf("%d\n",cnt);
    return 0;
}
