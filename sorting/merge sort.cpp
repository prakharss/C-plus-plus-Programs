/*
merge sort 
stable sorting algorithm
not inplace algorithm means it need some auxialiary space
O(n*log n) S(n)
*/

#include <bits/stdc++.h>
using namespace std;

void mergeTwoSortedHalves(int arr[],int l,int m,int r)
{
	int n1=m-l+1,n2=r-m,i,j,k;
	int t1[n1],t2[n2];
	
	for(i=0;i<n1;i++)
		t1[i]=arr[i+l];
	
	for(i=0;i<n2;i++)
		t2[i]=arr[m+1+i];
	
	i=0; j=0; k=l;
	while(i<n1 && j<n2)
	{
		if(t1[i]<=t2[j])
		{
			arr[k]=t1[i];
			i++; k++;
		}
		else if(t1[i]>t2[j])
		{
			arr[k]=t2[j];
			j++; k++;
		}
	}
	
	while(i<n1)
	{
		arr[k]=t1[i]; i++; k++;
	}

	while(j<n2)
	{
		arr[k]=t2[j]; j++; k++;  
	}
}

void mergeSort(int arr[],int l,int r)
{
	if(l<r)
	{
		int m=(l+r)/2;
		mergeSort(arr,l,m); //1
		mergeSort(arr,m+1,r); //2
		
		mergeTwoSortedHalves(arr,l,m,r); //Merge the two halves sorted in step 1 and 2
	}
}

int main()
{
   int i,n;
   cin>>n;
   int a[n];
   for(i=0;i<n;i++)
   		cin>>a[i];

	mergeSort(a,0,n-1);
	
	for(i=0;i<n;i++)
   		cout<<a[i]<<" ";
   		
    return 0;
}


