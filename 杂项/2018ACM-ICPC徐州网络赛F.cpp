#include<bits/stdc++.h>
using namespace std;


map<pair<int,int>,int> m1;
map<pair<int,int>,int> m2;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        int ans = 0;
        map<pair<int,int>,int>::iterator ite;
        pair<int,int> pai;
        for(int i=1; i<=n; i++)
        {
            int k;
            scanf("%d",&k);
            if(k==0)
            {
                m1.clear();
                m2.clear();
                continue;
            }
            for(int j=1; j<=k; j++)
            {
                scanf("%d%d",&pai.first,&pai.second);
                if(i%2==0) //m2
                {
                    ite = m1.find(pai);
                    if(ite == m1.end())
                    {
                        m2[pai] = 1;
                        ans = max(ite->second+1,ans);
                    }
                    else
                    {
                        m2[pai] = ite->second+1;
                        ans = max(ite->second+1,ans);
                    }
                }
                else    //m1
                {
                    ite = m2.find(pai);
                    if(ite == m2.end())
                    {
                        m1[pai] = 1;
                        ans = max(ite->second+1,ans);
                    }
                    else
                    {
                        m1[pai] = ite->second+1;
                        ans = max(ite->second+1,ans);
                    }
                }
            }
            if(i%2 == 0)
                m1.clear();
            else
                m2.clear();
        }
        cout<<ans<<endl;
    }
    return 0;
}
