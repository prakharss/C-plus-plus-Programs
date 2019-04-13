/*
radix sort
generally all are comparison based sorting algo (quick, merge, heap, bubble, selection, insertion) except radix and counting sort
O((n+b)*log10(mx)) S(n) where b is the base for representing numbers
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int li;

//O(n+b) where b is the base for representing numbers
void stableCountingSortAlgo(li arr[],li mul,li n)	//we need a stable sorting algorithm
{
	li output[n],i;
	li hash[10]={0};

	for(i=0;i<n;i++)
		hash[(arr[i]/mul)%10]++;
	
	for(i=1;i<=9;i++)
		hash[i]=hash[i]+hash[i-1];
	
	for(i=n-1;i>=0;i--)		//to make it stable we move from reverse direction 
	{
		output[hash[(arr[i]/mul)%10]-1]=arr[i];
		hash[(arr[i]/mul)%10]--;
	}
	
	for(i=0;i<n;i++)
		arr[i]=output[i];
}

//O((n+b)*log10(mx))
void radixSort(li arr[],li n)
{
	li mul=1; 
	li mx=*max_element(arr,arr+n);
	while(mx/mul>0)
	{
		stableCountingSortAlgo(arr,mul,n);
		mul=mul*10;
	}
}

int main()
{
   li i,n;
   cin>>n;
   li arr[n];

   for(i=0;i<n;i++)
   		cin>>arr[i];

	radixSort(arr,n);
	
	for(i=0;i<n;i++)
		cout<<arr[i]<<" ";
    
    return 0;
}


