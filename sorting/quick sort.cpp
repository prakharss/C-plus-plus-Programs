/*
quick sort having 2 logic for partition
non stable sorting algorithm
inplace sorting algorithm
O(n^2) worst case when when array is sorted and pivot is taken as first or last T(n)=T(1)+T(n-2)+O(n) 
O(n*log n) when pivot is selected randomly T(n)=2*T(n/2)+O(n) or taken as median of array T(n)=2*T(n/2)+2*O(n). This is used in practical purposes.
S(n) space on function call stack. We can decrease extra space to S(log n) 
https://www.geeksforgeeks.org/quicksort-tail-call-optimization-reducing-worst-case-space-log-n/
no extra space other than function call stack
randomised quick sort https://cs.stackexchange.com/questions/35994/why-does-randomized-quicksort-have-on-log-n-worst-case-runtime-cost
space complexity of heap sort is S(1) and quick sort S(log n) - still quick sort is better than heap sort
constant factors are smaller for quick sort and that's why it is used in practical purposes and better than heap sort
quick sort has better locality of reference.By contrast, heapsort jumps around significantly more.
why does heap sort have a space complexity of O(1) and quick sort have time complexity of O(log n)?
https://stackoverflow.com/questions/22233532/why-does-heap-sort-have-a-space-complexity-of-o1
*/

#include<bits/stdc++.h>
using namespace std;

int partition_logic_hoare(int a[],int l,int r)
{
	int temp=a[r],i,j;        //pivot is the last element
	i=l;   j=r-1;
	
	while(i<j)
	{
		while(a[i]<temp && i<=r-1)
			i++;
	
		while(a[j]>temp && j>=l)
			j--;
	
		if(i<j)
			swap(a[i],a[j]);
	}

	swap(a[i],a[r]);
	return i;
}

int partition_logic_lomuto(int a[],int l,int r)
{
	int temp=a[r],i,j;        //pivot is the last element
	
	i=l;  
	for(j=l;j<=r-1;j++)
	{
		if(a[j]<=temp)
		{
			swap(a[i],a[j]);
			i++;
		}
	}
	
	swap(a[i],a[r]);
	return i;
}

void quick_sort(int a[],int l,int r)
{
	if(l<r)
	{
		int ind=partition_logic_lomuto(a,l,r);
		quick_sort(a,l,ind-1);
		quick_sort(a,ind+1,r);
	}
}

int main()
{
   int i,n;
   cin>>n;
   int a[n];
   for(i=0;i<n;i++)
   		cin>>a[i];
	
	quick_sort(a,0,n-1);
	
	for(i=0;i<n;i++)
   		cout<<a[i]<<" ";

   return 0;
}


