/*
selection sort
take the minimum value and put it in the starting
O(n^2) S(1)
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int i,j,n,ind;
	cin>>n;
	int a[n];

	for(i=0;i<n;i++)
		cin>>a[i];
			
	for(i=0;i<n-1;i++)
	{
		mn=a[i];  ind=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<mn)
			{
				mn=a[j];
				ind=j;
			}
		}

		swap(a[i],a[ind]);
	}

	for(i=0;i<n;i++)
		cout<<a[i]<<" ";

	return 0;
}

