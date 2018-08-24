#include <bits/stdc++.h>
using namespace std;
/*
D: [What are you doing at the end of the world? Are you busy? Will you save us?]
A: [What are you doing while sending "]
B: ["? Are you busy? Will you send "]
C: ["?]

*/

string a = "What are you doing while sending \"";
string b = "\"? Are you busy? Will you send \"";
string c = "\"?";
string d = "What are you doing at the end of the world? Are you busy? Will you save us?";
long long leng[100001];
string ans;
char kevinGotThis(long long n, long long k)	//返回f[n]的第K个字符
{
	//cout<<"num:"<<n<<" "<<leng[n]<<" "<<k<<endl;
	//f[n] = A + f[n-1] + B + f[n-1] + C
	if(k>=leng[n])	//超出范围
	{
		//cout<<k<<" "<<leng[n]<<endl;
		//printf("k:%lld leng[n]:%lld\n",k,leng[n]);
	    return '.';
	}
	if(n==0)
		return d[k];
	if(k<a.size())	//在字符串A中
		return a[k];
    k-=a.size();
	if(k<leng[n-1])	//在f[n-1]中
	    return kevinGotThis(n-1,k);
    k-=leng[n-1];
	if(k<b.size())	//在字符串B中
		return b[k];
    k-=b.size();
	if(k<leng[n-1])	//在第二个f[n-1]中
	    return kevinGotThis(n-1,k);
	k-=leng[n-1];
	if(k<c.size())
		return c[k];
}
int main()
{
	int q;
	scanf("%d",&q);
	leng[0] = d.size();
	for(int i = 1; i<56;i++)	//0-53
		leng[i] = a.size() + leng[i-1] + b.size() + leng[i-1] + c.size();
	for(int i=56;i<=100000;i++)
		leng[i] =LLONG_MAX;
	long long n,k;
	ans = "";
	for(int i=0; i<q; i++)
	{
		cin>>n>>k;
		//cout<<n<<" "<<leng[n]<<" "<<k<<endl;
		//printf("leng: %lld \n",leng[n] );
		ans += kevinGotThis(n,k-1); //k-1转为从0开始计数
	}
	cout<<ans<<endl;
	return 0;
}
