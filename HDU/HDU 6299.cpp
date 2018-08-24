#include<bits/stdc++.h>
using namespace std;

int ans;
const int maxn = 100000+5;
struct node
{
    int l,r;    //左括号右括号
}v[maxn];

bool cmp(node a,node b)
{
    /*
    ** a b均为 左括号较多  将其放左边  最大利用左括号匹配
    ** 如果两个都是左括号较多  比较右括号 右括号少的放左边  最大匹配右括号
    ** 右括号较多同理
    */
    if(a.l > a.r)
        return b.l > b.r? a.r < b.r : true;
    if(a.l <= a.r)
        return b.l <= b.r? a.l > b.l :  false;
}

node pre_deal(char str[])
{
    int len = strlen(str);
    stack<char> s;
    node tmp = {0,0};
    for(int i=0; i<len; i++)
    {
        if(str[i] == ')')
        {
            if(s.empty())
            {
                s.push(')');
                tmp.r++;
            }
            else if(s.top() == '(')
            {
                s.pop();
                tmp.l--;
                ans+=2;
            }
            else
            {
                s.push(')');
                tmp.r++;
            }
        }
        if(str[i] == '(')
        {
            s.push('(');
            tmp.l++;
        }
    }
    return tmp;
}

char input[5000010];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        ans = 0;
        for(int i=1; i<=n; i++)
        {
            scanf("%s",input);
            v[i] = pre_deal(input);
        }
        int unused = 0;
        sort(v + 1,v + n + 1,cmp);
        for(int i = 1; i <= n; i++)
        {
            if(v[i].r > unused)
                v[i].r = unused;
            ans += 2*v[i].r;
            unused -= v[i].r;
            unused += v[i].l;
        }
        printf("%d\n",ans);
    }
}
