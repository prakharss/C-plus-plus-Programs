/*
kadanes algorithm which helps to find maximum contiguous sub array 
O(n) S(1)
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int i,n,mx,sum;
	cin>>n;
	int a[n];
	
	for(i=0;i<n;i++)
		cin>>a[i];
	
	sum=0; mx=INT_MIN;
	for(i=0;i<n;i++)
	{
		sum=sum+a[i];
		mx=max(mx,sum);
		if(sum<0)
			sum=0;
	}
	
	cout<<mx;
	return 0;
}


