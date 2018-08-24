#include<bits/stdc++.h>
using namespace std;

struct node{
    char str[10];
    int num;
};

bool operator<(node a, node b)
{
    return a.num<b.num;
}

priority_queue<node> q;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int t;
        scanf("%d",&t);
        while(t--)
        {
            node tmp;
            scanf("%s %d",tmp.str,&tmp.num);
            q.push(tmp);
        }
        printf("%s",q.top().str);
        q.pop();
        while(!q.empty())
        {
            printf(" %s",q.top().str);
            q.pop();
        }
        cout<<endl;
    }
    return 0;
}
