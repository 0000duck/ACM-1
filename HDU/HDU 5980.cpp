#include<bits/stdc++.h>
using namespace std;
#define ll long long

int check(ll tmp)
{
    string n97 = "01100001";
    string s = "";
    int rtn = 0;
    for(int i=1; i<=32; i++)
    {
        if(tmp&1 == 1)
            s.insert(0,"1");
        else
            s.insert(0,"0");
        tmp = tmp>>1;
        if(i%8 == 0)
        {
            //cout<<s<<endl;
            if(s == n97)
                rtn++;
            s.clear();
        }
    }
    return rtn;
}

int main()
{
    int N;
    while(~scanf("%d",&N))
    {
       ll tmp;
        int ans = 0;
        for(int i=0; i<N; i++)
        {
            scanf("%lld",&tmp);
            int tes = check(tmp);
            ans += tes;
        }
        printf("%d\n",ans);
    }
    return 0;
}
