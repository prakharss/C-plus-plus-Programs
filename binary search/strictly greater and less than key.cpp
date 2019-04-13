/*
value just strictly greater and less than key
O(log n) if array is already sorted otherwise O(n*log n) and S(1)
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int li;

li strictlyGreater(int a[],int n,int key)
{
	li l,r,mid
	l=0;  r=n-1;
	while(l<=r)        
	{
		mid=(l+r)/2;
		if(a[mid]<=key)
			l=mid+1;
		else if(a[mid]>key)
			r=mid-1;
	}

	return l; //here l will give value strictly greater than key and r will give value less than or equal to key
}

li strictlyLesser(int a[],int n,int key)
{
	l=0;  r=n-1;
	while(l<=r)              
	{
		mid=(l+r)/2;
		if(a[mid]<key)
			l=mid+1;
		else if(a[mid]>=key)
			r=mid-1;
	}
	
	return r; //here r will give value strictly less than key and l will give value greater than or equal to key
}

int main()
{
	li i,n,key;
	cin>>n;
	li a[n];
	
	for(i=0;i<n;i++)
		cin>>a[i];
	
	cin>>key;

	ind=strictlyGreater(a,n,key);	
	if(ind<n)
		cout<<a[ind];
	else 
		cout<<-1;

	ind=strictlyLesser(a,n,key);	
	if(ind>=0)
		cout<<a[ind];
	else 
		cout<<-1;

	return 0;			
}



