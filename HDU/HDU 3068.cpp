#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX = 220010;

char s[MAX];
char new_s[MAX*2];
int p[MAX*2];

int Init()
{
    int len = strlen(s);
    new_s[0] = '$';
    new_s[1] = '#';
    int j = 2;

    for(int i=0; i<len; i++)
    {
        new_s[j++] = s[i];
        new_s[j++] = '#';
    }
    new_s[j] = '\0';

    return j;
}

int Manacher()
{
    int len = Init();
    int maxlen = -1;

    int id;
    int mx = 0;

    for(int i=1; i<len; i++)
    {
        if(i < mx)
            p[i] = min(p[2*id - i], mx - i);
        else
            p[i] = 1;

        while(new_s[i - p[i]] == new_s[i + p[i]])
            p[i]++;
        if(mx < i + p[i])
        {
            id = i;
            mx = i + p[i];
        }
        maxlen = max(maxlen, p[i] - 1);
    }

    return maxlen;
}
int main()
{
    while(~scanf("%s",s))
    {
        printf("%d\n",Manacher());
    }
    return 0;
}
