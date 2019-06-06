#include<bits/stdc++.h> 
using namespace std; 

int minimumSwaps(int arr[], int n) 
{ 
	pair<int, int> pa[n]; 
	int vis[n]={0};
	int ans,i,cycleSz,j; 
	for (i=0;i<n;i++) 
	{ 
		pa[i].first=arr[i]; 
		pa[i].second=i; 
	} 

	sort(pa,pa+n); 
	
	ans=0;
	for (i=0;i<n;i++) 
	{ 
		if (vis[i] || pa[i].second==i) 
			continue; 

		cycleSz=0; j=i; 
		while(!vis[j]) 
		{ 
			vis[j]=1; 
			j=pa[j].second; 
			cycleSz++; 
		} 

		if (cycleSz>0) 
			ans=ans+(cycleSz-1); 	
	} 

	return ans; 
} 

int main() 
{
	int n,i;
	cin>>n;
	
	int arr[n];
	
	for(i=0;i<n;i++)
		cin>>arr[i]; 
	
	cout<<minimumSwaps(arr,n); 
	return 0; 
} 

