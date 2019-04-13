//PROPERTY USED HERE FOR COMPOSITE NUMBERS - Every composite number has at least one prime factor less than or equal to square root of itself

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
//vector<li> vec;
//pair<li,li> pa[1000000];
//string str1,str2;
//li a[1000000];

int solve_this()
{
	li i,n;
	cin>>n;
	while(!(n%2))
	{
		n=n/2;
		cout<<2<<" ";
	}
		
	
	for(i=3;i<=sqrt(n);i+=2)
	{
		while(!(n%i))
		{
			n=n/i;
			cout<<i<<" ";	
		}
	}
	
	if(n>1)
		cout<<n<<" ";
		
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


