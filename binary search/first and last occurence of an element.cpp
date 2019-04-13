/*
first and last occurence of an element in a given sorted array
O(log n) S(1)
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int li;

li firstOccurence(li a[],li key,li n)
{
	li l,r,mid,i;
	l=0; r=n-1;
	while(l<=r)        
	{
		mid=(l+r)/2;
		if(a[mid]<key)
			l=mid+1;
		else if(a[mid]>=key) //just think seperately for the condition when(a[mid]==key)
			r=mid-1;
	}
	
	return l;
}

li lastOccurence(li a[],li key,li n)
{
	li l,r,mid,i;
	l=0; r=n-1;
	while(l<=r)        
	{
		mid=(l+r)/2;
		if(a[mid]<=key) //just think seperately for the condition when(a[mid]==key)
			l=mid+1;
		else if(a[mid]>key)
			r=mid-1;
	}
	
	return r;
}

bool elementExist(li a[],li key,li n)
{
	li l,r,mid;
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
	li i,n,key;
	cin>>n;
	li a[n];
	
	for(i=0;i<n;i++)
		cin>>a[i];
		
	cin>>key;
	if(!elementExist(a,key,n))
		cout<<-1;
	else
	{
		cout<<firstOccurence(a,key,n)<<"\n";
		cout<<lastOccurence(a,key,n);
	}					
}


