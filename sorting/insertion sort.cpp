/*
insertion sort
in first loop, 1 element will be sorted and in second loop, 2 element will be sorted and in third loop, 3 element will be sorted and so on
O(n^2) S(1)
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int i,n,temp,j;
	cin>>n;
	int arr[n];

	for(i=0;i<n;i++)
		cin>>arr[i];

	for(i=1;i<n;i++)
	{
		temp=arr[i];
		for(j=i-1;j>=0;j--)
		{
			if(temp<arr[j])
				arr[j+1]=arr[j];
			else
				break;
		}

		arr[j+1]=temp;
	}

	for(i=0;i<n;i++)
		cout<<arr[i]<<" ";
	
	return 0;
}

