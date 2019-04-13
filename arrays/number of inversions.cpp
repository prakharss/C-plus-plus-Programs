/*
find number of inversions
inversions means pair of (i,j) such that i<j and a[i]>a[j]
look at the 2 ways we used
O(n*log n) S(n)
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int li;

li inv[1000000]={0};
li merge(li arr[],li l,li mid,li r)
{
	li n1=mid-l+1,n2=r-mid;
	li t1[n1],t2[n2];
	li i,j,k,invCount;

	for(i=0;i<n1;i++)
		t1[i]=arr[i+l];
		
	for(i=0;i<n2;i++)
		t2[i]=arr[mid+1+i];
		
	i=0; j=0; invCount=0;
	while(i<n1 && j<n2)
	{
		if(t1[i]<t2[j])
		{
			arr[l]=t1[i];
			i++; l++;
		}
		else if(t1[i]>=t2[j])
		{
			arr[l]=t2[j];
			j++; l++;
			invCount=invCount+(n1-i); //we will return invCount as total number of inversions
			inv[i+l]=inv[i+l]+(n1-i); //using a global variable
		}
	}
	
	for(k=i;k<n1;k++)
	{
		arr[l]=t1[k];  l++;
	}
	
	for(k=j;k<n2;k++)
	{
		arr[l]=t2[k];  l++;
	}

	return invCount;
}

li mergeSort(li arr[],li l,li r)
{
	li invCount=0;
	if(l<r)
	{
		li mid=(l+r)/2;
		invCount=invCount+merge_sort(arr,l,mid);
		invCount=invCount+merge_sort(arr,mid+1,r);
		
		invCount=invCount+merge(arr,l,mid,r);
	}

	return invCount;
}

int main()
{
	li i,n;
	cin>>n;
	li a[n];

	for(i=0;i<n;i++)
		cin>>a[i];
		
	cout<<mergeSort(a,0,n-1); //by returning inversions in a recursion

	ans=0;
	for(i=0;i<n;i++)
		ans=ans+inv[i]; //using a global variable
	cout<<ans;
	
	return 0;
}


