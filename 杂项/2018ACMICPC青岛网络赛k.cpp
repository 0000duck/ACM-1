#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;

int cnt[40];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        int tmp,ret;
        memset(cnt,0,sizeof(cnt));
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&tmp);
            ret=0;
            while(tmp!=0)
            {
                tmp = tmp>>1;
                ret++;
            }
            cnt[ret]++;
        }
        int ans = 0;
        for(int i=0; i<40; i++)
        {
            ans = max(ans,cnt[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}
