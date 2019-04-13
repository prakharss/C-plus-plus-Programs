/*
number of 1 in binary representation of a number
O(num of 1)
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int li;

int main()
{
	li x,ans=0;
	scanf("%ld",&x);
	while(x)
	{
		x=x&(x-1);
		ans++;	
	}

	cout<<ans<<"\n";		
}



