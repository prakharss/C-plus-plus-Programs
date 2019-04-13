/*
counting sort
generally all are comparison based sorting algo (quick, merge, heap, bubble, selection, insertion) except radix and counting sort
for complexity refer functions
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int li;

//O(n + (mx-mn)) S(n + mx)
void stableCountingSort(li arr[],li n)  //this logic is used in radix sort 
{
	li i,temp,cnt;
	li mx=*max_element(arr,arr+n)
	li mn=*min_element(arr,arr+n);
	li hash[mx+1]={0};
	li output[n];
	
	for(i=0;i<n;i++)
		hash[arr[i]]++;
	
	for(i=mn+1;i<=mx;i++)
		hash[i]=hash[i]+hash[i-1];	//hash[i] denotes the position of array indices in the sorted form
	
	for(i=n-1;i>=0;i--)	 //to make it stable we move from reverse direction
	{
		output[hash[arr[i]]-1]=arr[i];
		hash[arr[i]]--;
	}
	
	for(i=0;i<n;i++)
		arr[i]=output[i];
}

//O(n + (mx-mn)) S(mx)
void countingSortByArray(li arr[],li n)
{
	li i,temp,cnt;
	li mx=*max_element(arr,arr+n);
	li mn=*min_element(arr,arr+n);
	li hash[mx+1]={0};
	
	for(i=0;i<n;i++)
		hash[arr[i]]++;
	
	cnt=0;
	for(i=mn;i<=mx;i++)
	{
		temp=hash[i];
		while(temp--)
		{
			arr[cnt]=i; cnt++;
		}
	}
}

int main()
{
	li i,n;
	cin>>n;
	li a[n],b[n],c[n];

	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=0;i<n;i++)
		cin>>b[i];
	for(i=0;i<n;i++)
		cin>>c[i];

	stableCountingSort(a,n);
	countingSortByArray(b,n);
   
	for(i=0;i<n;i++)
		cout<<a[i]<<" "; cout<<"\n";
	for(i=0;i<n;i++)
		cout<<b[i]<<" "; cout<<"\n";
	for(i=0;i<n;i++)
		cout<<c[i]<<" ";
   
   return 0;
}

