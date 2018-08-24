#include<bits/stdc++.h>
using namespace std;
const int MAXN = 10010;

struct Node{
    vector<int> V;
}node[MAXN];

int ran[MAXN];      //记录点的染色值
int pos[MAXN];      //状态压缩值
queue<int> q;
int N,M,L;

void rand_color()
{
    for(int i=1; i<=N; i++)
    {
        ran[i] = 1<<(rand()%(L+1));
        //printf("ran[%d] = %d\n",i,ran[i]);
    }
}

int cal(int n)
{
    int ans = 0;
    for(int i=0; i<n; i++)
    {
        ans += 1<<i;
    }
    return ans;
}
void show_node()
{
    for(int i=1; i<=N; i++)
    {
        int ll = node[i].V.size();
        for(int j=0; j<ll; j++)
        {
            printf("%d -- %d\n",i,node[i].V[j]);
        }
    }
}

int main()
{
    while(scanf("%d %d %d",&N,&M,&L) == 3)
    {
        srand((int)time(0));
        int turn = (int)pow(3,N);
        int flag = 0;
        int u,v;
        for(int i=1; i<=MAXN; i++)
            node[i].V.clear();
        for(int i=1; i<=M; i++)
        {
            scanf("%d %d",&u,&v);
            node[u].V.push_back(v);
        }
        int S,T;
        scanf("%d %d",&S,&T);
        while(turn--)
        {
            rand_color();
            memset(pos,0,sizeof(pos));
            while(!q.empty()) q.pop();
            pos[S] = ran[S];
            q.push(S);
            //show_node();
            while(!q.empty())
            {
                int temp = q.front();
                q.pop();
                int ll = node[temp].V.size();
                for(int i=0; i<ll; i++)     //遍历与temp连通的点
                {
                    int k = node[temp].V[i];
                    if((ran[k] | pos[temp]) > pos[temp])
                    {
                        q.push(k);
                        pos[k] = (ran[k] | pos[temp]);
                        //printf("pos[%d] = %d",k,pos[k]);
                    }
                }
            }

            if(pos[T] == cal(L))
            {
                flag = 1;
                break;
            }
        }
        if(flag)
            printf("YES\n");
        else
        {
            flag = 0;
            printf("NO\n");
        }
    }
    return 0;
}
