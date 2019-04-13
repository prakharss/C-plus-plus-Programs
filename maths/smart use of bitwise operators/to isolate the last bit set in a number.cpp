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
#define maxi 1e18    //value of INT_MAX is 2*pow(10,9)
//vector<li> vec;
//pair<li,li> pa[1000000];
//string str1,str2;
//li a[1000000];

void solve_this()
{
	li i,n;
	for(n=1;n<=20;n++)
	{
	cout<<n<<" & "<<-n<<" is ";
	i=n&-n;
	cout<<i<<"\n\n";
	}	
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


