#include<bits/stdc++.h>
using namespace std;
const int MAXN = 8;
int chess[MAXN][MAXN];
int cnt = 0;

int in_chess(int x,int y)
{
    return (x<MAXN && x>=0 && y<MAXN && y>=0);
}

int check(int x,int y) //�жϻʺ����λ��x,y�Ƿ���ڻ���
{
    int xx,yy;
    for(int i=0; i<MAXN; i++)
    {
        if(chess[x][i] || chess[i][y])  //��Ӧ����
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
    while(in_chess(xx,yy)) //  ����/
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

void dfs(int q) //�ѵ�q���ʺ���ڵ�q��
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
