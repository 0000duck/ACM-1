 /*
 矩阵快速幂模板题
 */
#include<bits/stdc++.h>
using namespace std;
const int maxn = 2;
const int mod = 7;
struct matrix
{
    int m[2][2];
};

matrix multi(matrix a, matrix b)
{
    matrix tmp;
    for(int i=0; i<maxn; i++)
    {
        for(int j=0; j<maxn; j++)
        {
            tmp.m[i][j] = 0;
            for(int k=0; k<maxn; k++)
                tmp.m[i][j] += (a.m[i][k]*b.m[k][j])%mod;
            tmp.m[i][j]%=mod;
        }
    }
    return tmp;
}

matrix fastPow(matrix base, int n)
{
    matrix ans;
    for(int i=0; i<maxn; i++)
        for(int j=0; j<maxn; j++)
            ans.m[i][j] = (i==j);

    while(n)
    {
        if(n&1)
            ans = multi(ans, base);
        base = multi(base, base);
        n>>=1;
    }
    return ans;
}

int main()
{
    int a,b,n;
    while(scanf("%d %d %d",&a,&b,&n))
    {
        if(!a && !b && !n)
        break;
        if(n==1 || n==2)
        {
            printf("1\n");
            continue;
        }
        matrix tmp;
        tmp.m[0][0] = a%mod;
        tmp.m[0][1] = b%mod;
        tmp.m[1][0] = 1;
        tmp.m[1][1] = 0;
        matrix ans = fastPow(tmp,n-2);
        printf("%d\n",(ans.m[0][0]+ans.m[0][1])%7);
    }
    return 0;
}
