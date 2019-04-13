/*
Given an array of n elements, where each element is at most k away from its target position, devise an algorithm that sorts in O(n log k) time.
For example, let us consider k is 2, an element at index 7 in the sorted array, can be at indexes 5, 6, 7, 8, 9 in the given array.
O(n*log(k)) S(k)
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

//O(k + (n-k)*log(k) + k*log(k)) i.e O(k + n*log(k)) i.e O(n*log(k)) S(1)
void utilFunction(li a[],li n,li k)
{
    li i,j,m=k+1;
    
	for(i=m/2;i>=0;i--) //O(k) build heap for k+1 elements
		heapifyMin(a,i,m); 
	
	for(j=m;j<n;j++) //push next element and extract minimum from element
	{
		cout<<a[0]<<" ";
		a[0]=a[j];
		heapifyMin(a,0,m);
	}

	for(i=k;i>=0;i--) //extract all remaining elements
	{
        cout<<a[0]<<" ";  
		a[0]=a[i];
		heapifyMin(a,0,i);
	}
}

int main()
{
	li i,n,k;
	cin>>n>>k;
	li a[n];

	for(i=0;i<n;i++)
		cin>>a[i];

	utilFunction(a,n,k);
	return 0;
}

/*
void usingPriorityQueue(li a[],li n,li k)
{
	li i,j;
	priority_queue<li, vector<li>, greater<li> > mnpq; //min heap

	for(i=0;i<k+1;i++)
		mnpq.push(a[i]);

	for(j=i;j<n;j++)
	{
		cout<<mnpq.top()<<" ";
		mnpq.pop();
		mnpq.push(a[j]);
	}

	while(!mnpq.empty())
	{
		cout<<mnpq.top()<<" ";
		mnpq.pop();
	}
}
*/
