/*
count of all occurences of a number
O(log n) if array is already sorted otherwise O(n*log n) and S(1)
if input array is not sorted then we have a better solution of O(n) by iterating the array once
*/

#include<bits/stdc++.h>
using namespace std;

int firstOccurence(int a[],int key,int n)
{
	int l,r,mid;
	l=0; r=n-1;
	while(l<=r)        
	{
		mid=(l+r)/2;
		if(a[mid]<key)
			l=mid+1;
		else if(a[mid]>=key)
			r=mid-1;
	}
	
	return l;
}

int lastOccurence(int a[],int key,int n)
{
	int l,r,mid;
	l=0; r=n-1;
	while(l<=r)       
	{
		mid=(l+r)/2;
		if(a[mid]<=key)
			l=mid+1;
		else if(a[mid]>key)
			r=mid-1;
	}
	
	return r;
}

bool elementExist(int a[],int key,int n)
{
	int l,r,mid;
	l=0; r=n-1;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(a[mid]<key)
			l=mid+1;
		else if(a[mid]>key)
			r=mid-1;
		else
			return true;
	}

	return false;
}

int main()
{
	int i,n,key;
	cin>>n;
	int a[n];
	
	for(i=0;i<n;i++)
		cin>>a[i];
	
	cin>>key;
	if(!elementExist(a,key,n))
		cout<<-1;
	else
		cout<<lastOccurence(a,key,n)-firstOccurence(a,key,n)+1;
		
	return 0;
}


