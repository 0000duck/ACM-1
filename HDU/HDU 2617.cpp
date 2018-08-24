#include<bits/stdc++.h>
#include<cstring>
using namespace std;

char str[10100];
int che[5];
int main()
{
    while(gets(str))
    {
        int len = strlen(str);
        int cnt =0;
        memset(che,0,sizeof(che));
        for(int i=0; i<len; i++)
        {
            if(str[i]=='h') //h
            {
                che[1]++;
            }
            else if((str[i]=='a') && che[1]>che[2])        //ha
            {
                che[2]++;
            }
            else if((str[i]=='p') && che[2]>(che[3]/2))        //hap
            {
                che[3]++;
            }
            else if((str[i]=='y') && (che[3]/2)>che[4])       //happy
            {
                che[4]++;
            }
        }
        printf("%d\n",che[4]);
    }
    return 0;
}
