#include<bits/stdc++.h>
using namespace std;
typedef long long int li;
#define cc continue
#define bb break
#define rr return
#define W while
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define INF 0x3f3f3f3f   //by this INF is equal to INT_MAX/2 which is safe to take as INT_MAX may overflow during operation
//vector<li> vec;
//pair<li,li> pa[1000000];
//string str1,str2;
//li a[1000000];

li power(li x,li y)
{
    li res=1;
    while(y>0)
    {
	    if(y&1)
	        res=(res*x)%mod;
	    
	    y=y>>1;
	    x=(x*x)%mod;
	}
    return res;
}

li nCr(li n,li r)
{
	li factn,factr,factrem,i,dominator,rem=n-r;
	
	factn=factr=factrem=1;
    
	for(i=1;i<=n;i++)
        factn=(factn*i)%mod;
    
	for(i=1;i<=r;i++)
        factr=(factr*i)%mod;
    
	for(i=1;i<=rem;i++)
        factrem=(factrem*i)%mod;
    
    dominator=(factr*factrem)%mod;
    return (factn*(power(dominator,mod-2)))%mod;           //(x inverse) mod p if prime then it is equal to (x^(p-2)) mod p
}

int solve_this()
{
	li n,r;
	cin>>n>>r;
	cout<<nCr(n,r);
	rr 0;
}

int main()
{
ios_base::sync_with_stdio(false); cin.tie(0);
//freopen("i.txt","r",stdin);
//freopen("o.txt","w",stdout);
//li T;  cin>>T;  W(T--)
solve_this();
rr 0;
}


