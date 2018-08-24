#include<bits/stdc++.h>
using namespace std;

const int maxn =  5e6 + 50;
bitset<1005> b[20];
bitset<1005> ans;

char str[maxn];
int main()
{
    int N;
    while(~scanf("%d",&N))
    {
        for(int i=0; i<N; i++)
        {
            int tmp,tol;
            scanf("%d",&tmp);
            for(int j=0; j<tmp; j++)
            {
                scanf("%d",&tol);
                b[tol].set(i);  //tol 这个数可以在第i位出现
            }
        }
        getchar();
        gets(str);
        int len = strlen(str);
        for(int i=0; i<len; i++)
        {
            ans = ans<<1;
            ans[0] = 1;
            ans&=b[str[i]-'0'];
            if(ans[N-1] == 1)
            {
                char temp = str[i+1];
                str[i+1] = '\0';
                puts(str+i-N+1);
                str[i+1] = temp;
            }
        }
    }
    return 0;
}
