#include<bits/stdc++.h>
using namespace std;
const int N = 9;
char chess[N][N];
int n,k,cnt;

//���Ƿ�λ��
int check(int x, int y)
{
    for(int i=0; i<n; i++)
    {
        if(chess[i][y] == '*' || chess[x][i] == '*')
            return 0;
    }
    return 1;
}

//����n�����Ӱڷ�
void dfs(int num)
{

}

int main()
{

    while(scanf("%d %d",&n,&k) && n!=-1 && k!=-1)
    {
        cnt = 0;
        for(int i=0; i<n; i++)
            scanf("%s", &chess[i]);
        dfs(1);
        printf("%d\n",cnt);
    }
    return 0;
}
