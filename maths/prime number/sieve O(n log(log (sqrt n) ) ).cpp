// problem statement - Given a number N, find all prime numbers upto N ( N included ).
// using sieve in O(sqrt(n)log(logn))

#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,i,u,m,chk,x,j;
	
	cin>>n;
	int a[n+1];
	
	for(i=2;i<=n;i++)
	a[i]=1;
	
	for(i=2;i*i<=n;i++)
	{
		if(a[i]==1)
		{
			for(j=i*i;j<=n;j=j+i)
				a[j]=0;
		}
	}
     
    cout<<"List of all prime numbers up to "<<n<<"\n";
    for(i=2;i<=n;i++)
    {
     	if(a[i]==1)
     	cout<<i<<"\n";
	}	
}

