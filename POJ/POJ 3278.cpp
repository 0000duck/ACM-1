#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
int vis[100100];

struct move{
    int pos;
    int time;
};

queue<move> q;
int N,K;

bool inLim(int n)
{
    if(n<0 || n>100000)
        return false;
    return true;
}

int main()
{
    while(scanf("%d %d",&N,&K) == 2)
    {
        if(N==K)
        {
            printf("0\n");
            continue;
        }
        memset(vis,0,sizeof(vis));
        while(!q.empty())
            q.pop();
        move temp = {N,0};
        int ans = 0;
        q.push(temp);
        while(!q.empty())
        {
            temp = q.front();
            q.pop();
            if(vis[temp.pos] == 0)
            {
                vis[temp.pos] = temp.time;
                if(temp.pos == K)
                    break;
                if(inLim(temp.pos*2) && vis[temp.pos*2]==0)
                {
                    move a = {temp.pos*2,temp.time+1};
                    q.push(a);
                }
                if(inLim(temp.pos+1) && vis[temp.pos+1]==0)
                {
                    move b = {temp.pos+1,temp.time+1};
                    q.push(b);
                }
                if(inLim(temp.pos-1) && vis[temp.pos-1]==0)
                {
                    move c = {temp.pos-1,temp.time+1};
                    q.push(c);
                }
            }
        }
        printf("%d\n",vis[temp.pos]);
    }
    return 0;
}
