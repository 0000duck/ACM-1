#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e5+10;
int a[maxn],n;

struct node{
    int in;
    int out;
    bool operator <(const node b) const
    {
        return out > b.out;
    }
};

priority_queue<int,vector<int>,greater<int> > q;
priority_queue<node> ans;

void init()
{
    while(!q.empty()) q.pop();
    while(!ans.empty()) ans.pop();
}
void solve()
{
    q.push(a[1]);
    for(int i=2; i<=n; i++)
    {
        int pro1=-1,pro2=-1;  //更换已配对所得收益   加入新配对得到收益
        if(!ans.empty() && ans.top().out < a[i])
        {
            pro1 = a[i] - ans.top().out;
        }
        if(!q.empty() && q.top() < a[i])
        {
            pro2 = a[i] - q.top();
        }
        if(pro1 == pro2 && pro1 == -1)
            q.push(a[i]);
        else if(pro1 >= pro2)
        {
            int tmp = ans.top().out;
            node tnode = ans.top(); ans.pop();
            tnode.out = a[i];
            ans.push(tnode);
            q.push(tmp);
        }
        else
        {
            node tmp = {q.top(),a[i]};
            q.pop();
            ans.push(tmp);
        }
    }
    ll ret = 0;
    int mov = 0;
    while(!ans.empty())
    {
        ret += (ans.top().out - ans.top().in);
        mov += 2;
        ans.pop();
    }
    cout<<ret<<" "<<mov<<endl;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
            scanf("%d",&a[i]);
        init();
        solve();
    }
}
