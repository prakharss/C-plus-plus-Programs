/*
bubble sort - swapping adjacent numbers 
inplace sorting algo
Here we swap the adjacent element so that in first loop,highest element comes at last and so on
O(n^2) S(1)
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int i,j,n,flag;
		cin>>n;
		for(i=0;i<n;i++)
			cin>>a[i];

	for(i=0;i<n-1;i++)
	{
		flag=1;
		for(j=0;j<n-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				swap(a[j],a[j+1]);
				flag=0;
			}
		}
		if(flag==1)
		break;
	}

	for(i=0;i<n;i++)
			cout<<a[i]<<" ";
		
	return 0;
}

