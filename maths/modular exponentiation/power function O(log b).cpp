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
li power(li x,li y)
{
	li ans=1;
	while(y)
	{
		if(y%2)
			ans=ans*x;
			
		x=x*x;
		y>>=1;
	}
	return ans;	
} 

int solve_this()
{
	li i,a,b;
	cin>>a>>b;
	cout<<power(a,b);
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


