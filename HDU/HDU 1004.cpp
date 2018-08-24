#include<bits/stdc++.h>
using namespace std;

map<string,int> m;

int main()
{
    int n;
    while(scanf("%d",&n))
    {
        if(n==0)
            break;
        m.clear();
        string tmp;
        for(int i=0; i<n; i++)
        {
            cin>>tmp;
            m[tmp]++;
        }
        string ans;
        map<string,int>::iterator ite;
        int rec = 0;
        for(ite = m.begin(); ite!=m.end(); ite++)
        {
            if(ite->second > rec)
            {
                rec = ite->second;
                ans = ite->first;
            }

        }
        cout<<ans<<endl;
    }
    return 0;
}
