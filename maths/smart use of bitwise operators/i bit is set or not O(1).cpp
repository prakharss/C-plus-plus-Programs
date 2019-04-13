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

bool check(li N,li i)
{
    if( N & (1 << i) )
        return true;
    else
        return false;
}

void solve_this()
{
	li i,n;
	cin>>n;
	cin>>i;   //here i=0 is the right most bit i.e 1st bit from right side and i=1 means 2nd bit from right side
	
	if(check(n,i))
	cout<<"given bit is set";
	else
	cout<<"given bit is not set";
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


