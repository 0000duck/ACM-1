#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e5+10;
const ll mod = 1e9+7;
struct node{
    int l,r;
    int id;
    int block;
}q[maxn];

ll Ans;
ll ans[maxn];
ll ini[maxn];
ll inv[maxn];
ll inv2;
int T,n,len;

ll C(int m, int n)
{
    return ( ( ini[n]*inv[m] ) %mod )*inv[n-m]%mod;
    //return ini[n]/(ini[m]*ini[n-m]);
}

ll quickpow(ll a,ll n) //a^n%k
{
    ll k = mod;
    ll b = 1;
    while (n)
    {
          if (n & 1)
             b = (b*a)%k;
          n = n >> 1 ;
          a = (a*a)%k;
    }
    return b;
}

bool cmp(node& a, node& b)
{
    if(a.block == b.block)
        return a.r<b.r;
    return a.block < b.block;
}

void init()
{
    ini[0]=1;
    inv[0] = quickpow(1,mod-2);
    inv2 = quickpow(2,mod-2);
    //cout<<inv2<<endl;
    for(int i=1; i<maxn; i++)  //½×³Ë ÄæÔª
    {
        ini[i] = ini[i-1]*i%mod;
        inv[i] = quickpow(ini[i],mod-2);
    }
}

void addn(int n, int m)
{
    Ans = ((2*Ans)%mod-C(m,n)+mod)%mod;
}

void delen(int n, int m)
{
    Ans = (( (Ans+C(m,n-1))%mod) *inv2)%mod;
}

void addm(int n, int m)
{
    Ans = (Ans+C(m, n))%mod;
    //cout<<m<<" "<<n<<" "<<C(m,n)<<endl;
}

void delem(int n, int m)
{
    Ans = (Ans-C(m, n)+mod)%mod;
    //cout<<m<<" "<<n<<" "<<C(m,n)<<endl;
}

int main()
{
    scanf("%d",&T);
    len = sqrt(T);
    for(int i=1; i<=T; i++) //¶ÁÈë
    {
        scanf("%d %d",&q[i].r,&q[i].l); //n, m  m < n
        q[i].id = i;
        q[i].block = q[i].l/len;
    }

    init();
    sort(q+1,q+1+T,cmp);

    int l=q[1].l,r=q[1].r;
    Ans=0;
    for(int i=0; i<=l; i++)
        addm(r, i); //n,m

    for(int i=1; i<=T; i++)
    {
        while(q[i].r < r)
            delen(r--, l);
        //cout << Ans << endl;
        while(q[i].r > r)
            addn(r++, l);
        //cout << Ans << endl;
        while(q[i].l < l)
            delem(r, l--);
        //cout << Ans << endl;
        while(q[i].l > l)
            addm(r, ++l);
        //cout << Ans << endl;
        ans[q[i].id] = Ans;
    }
    for(int i=1; i<=T; ++i)
        printf("%lld\n",ans[i]);
    return 0;
}
