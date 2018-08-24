#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e9+7;
char num[100100];
int deal_1[100100];
bool vis_1[100100];
int deal_2[100100];
bool vis_2[100100];
stack<int> sta1,sta2;   //sta1存放%3值为1的数位置的下标 sta2同理
int len;
int del_cnt1,del_cnt2;
bool flag;
void print(int n)
{
    if(n==1)
    {
        if(del_cnt1==len)
        {
            if(flag)
            {
                printf("0\n");
            }
            else
                printf("-1\n");
            return;
        }
        for(int i=0; i<len; i++)
            if(vis_1[i])
                printf(("%c"),num[i]);
    }
    else
    {
        if(del_cnt2==len)
        {
            if(flag)
            {
                printf("0\n");
            }
            else
                printf("-1\n");
            return;
        }
        for(int i=0; i<len; i++)
            if(vis_2[i])
                printf(("%c"),num[i]);
    }
    printf("\n");
}

void del(int n)     //计算前导0
{
    int cnt=0;
    if(n==1)
    {
        for(int i=0; i<len; i++)
            if(vis_1[i])
            {
                if(num[i]!='0')
                    return;
                else if(del_cnt1)
                {
                    vis_1[i]=false;
                    ++del_cnt1;
                }
            }
    }
    else if(n==2)
    {
        for(int i=0; i<len; i++)
            if(vis_2[i])
            {
                if(num[i]!='0')
                    return;
                else if(del_cnt2)
                {
                    vis_2[i]=false;
                    ++del_cnt2;
                }
            }
    }
}
int main()
{
    memset(vis_1,true,sizeof(vis_1));
    memset(vis_2,true,sizeof(vis_2));
    del_cnt1 = del_cnt2 = maxn;
    flag = false;
    len = strlen(num);
    int mod =0;
    for(int i=0; i<len; i++)
    {
        if(!flag && num[i]=='0')
            flag=true;
        deal_2[i] = deal_1[i] = (num[i]-'0')%3;
        mod += deal_1[i];
        if(deal_1[i]==1)
            sta1.push(i);
        else if(deal_2[i]==2)
            sta2.push(i);
    }
    mod%=3;
    if(mod == 0)
    {
        printf("%s\n",num);
        return 0;
    }
    else if(mod == 1)
    {
        if(!sta1.empty())
        {
            del_cnt1=0;
            vis_1[sta1.top()] = false;
            ++del_cnt1;
            del(1);
        }
        if(sta2.size()>=2)
        {
            del_cnt2=0;
            vis_2[sta2.top()] = false;
            sta2.pop();
            vis_2[sta2.top()] = false;
            sta2.pop();
            del_cnt2+=2;
            del(2);
        }
    }
    else
    {
        if(!sta2.empty())
        {
            del_cnt1=0;
            vis_1[sta2.top()] = false;
            ++del_cnt1;
            del(1);
        }
        if(sta1.size()>=2)
        {
            del_cnt2=0;
            vis_2[sta1.top()] = false;
            sta1.pop();
            vis_2[sta1.top()] = false;
            sta1.pop();
            del_cnt2+=2;
            del(2);
        }
    }

    if(del_cnt1>del_cnt2)
        print(2);
    else
        print(1);
    return 0;
}
