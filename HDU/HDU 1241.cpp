#include<cstdio>
#include<cstring>

const int MAX = 200;
char mm[MAX][MAX];
bool vis[MAX][MAX];
int dirx[8] = {0,1,1,1,0,-1,-1,-1};
int diry[8] = {-1,-1,0,1,1,1,0,-1};
//��������  ��Ӧ�˸�����
int m,n;

bool inmap(int x,int y) //�ж����� x,y �Ƿ��ڵ�ͼ��
{
    if(x<0 || x>m-1 || y<0 || y>n-1)
        return false;
    return true;
}

void dfs(int x,int y)   //  DFS  ɨ��x,y�˸����������
{
    for(int i=0; i<8; i++)
    {
        int mx = x + dirx[i];
        int my = y + diry[i];
        if(inmap(x,y) && !vis[mx][my]  && mm[mx][my]=='@')  //���������ڵ�ͼ��  û�з��ʹ� ����������  �ͱ������� �����ٴ�dfs
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
        memset(vis,false,sizeof(vis));  //��ʼ��vis Ϊ false
        for(int i=0; i<m; i++)      //��������
            scanf("%s",mm[i]);

        for(int i=0; i<m; i++)  //  ���������ͼ
            for(int j=0; j<n; j++)
                if(!vis[i][j] && mm[i][j]=='@') //  ���û�з��ʹ�����������  ����dfs
                {
                    ans++;
                    vis[i][j] = true;
                    dfs(i,j);
                }
        printf("%d\n",ans);
    }
}
