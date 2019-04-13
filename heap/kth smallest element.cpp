/*
find kth smallest element
refer function for complexity
we can make heap using bottom up approach in linear time
however push and pop will take log(n) time
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int li;

//O(log(n))
void heapifyMin(li a[],li i,li n)
{
	li left=2*i+1;
	li right=2*i+2;

	li smallest=i;

	if(left<n && a[smallest]>a[left])
		smallest=left;
	
	if(right<n && a[smallest]>a[right])
		smallest=right;

	if(smallest!=i)
	{
		swap(a[smallest],a[i]);
		heapifyMin(a,smallest,n);
	}
}

//O(log(n))
void heapifyMax(li a[],li i,li n)
{
	li left=2*i+1;
	li right=2*i+2;

	li largest=i;

	if(left<n && a[largest]<a[left])
		largest=left;
	
	if(right<n && a[largest]<a[right])
		largest=right;
	
	if(largest!=i)
	{
		swap(a[largest],a[i]);
		heapifyMax(a,largest,n);
	}
}

//O(n + k*log(n)) S(1)
li usingMinHeap(li a[],li n,li k)
{
	li i,j;
	for(i=n/2;i>=0;i--) //build min heap of size n in O(n)
		heapifyMin(a,i,n);

	j=n-1;
	for(i=0;i<k-1;i++) //extract one by one from min heap 
	{
		swap(a[0],a[j]);
		heapifyMin(a,0,j);
		j--;
	}

	return a[0]; //root after extracting k-1 elements	
}

//O(k + (n-k)*log(k)) S(1) 
//this can handle series of infinite numbers
li usingMaxHeap(li a[],li n,li k)
{
	li i,j;

	for(i=k/2;i>=0;i--) //build max heap of size k in O(k)
		heapifyMax(a,i,k); 

	for(j=k;j<n;j++)
	{
		if(a[j]<a[0]) //extract root element from heap when we found smaller than root
		{
			a[0]=a[j];
			heapifyMax(a,0,k);
		}
	}
	
	return a[0];
}

int main()
{
	li i,n,k,mn;
	cin>>n>>k;
	li a[n];
	   
	for(i=0;i<n;i++)
		cin>>a[i];  		
	
	cout<<usingMinHeap(a,n,k)<<"\n";
	cout<<usingMaxHeap(a,n,k);  

	return 0;
}

/*
li usingMaxHeapAndPriorityQueue(li a[],li n,li k)
{
	li i,j,tp;
	priority_queue<li> mxpq; //max heap

	for(i=0;i<k;i++)
		mxpq.push(a[i]); 
	
	for(j=i;j<n;j++)
	{
		tp=mxpq.top();
		if(a[j]<tp)
		{
			mxpq.pop();
			mxpq.push(a[j]);
		}
	}
	
	return mxpq.top();
}

li usingMinHeapAndPriorityQueue(li a[],li n,li k)
{
	li i;
	priority_queue<li, vector<li>, greater<li> > mnpq; //min heap by wirting in this format

	for(i=0;i<n;i++)
		mnpq.push(a[i]); 

	for(i=0;i<k-1;i++)
		mnpq.pop();

	return mnpq.top();		
}
*/