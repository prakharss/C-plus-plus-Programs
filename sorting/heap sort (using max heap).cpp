/*
heap sort
non stable sorting algorithm
inplace sorting algo
no extra space
space complexity of heap sort is S(1) and quick sort S(log n) 
O(n*log(n)) S(1)
*/

#include<bits/stdc++.h>
using namespace std;

void heapify(int a[],int ind,int n)
{
    int left=2*ind+1;
    int right=2*ind+2;
    
    int largest=ind;
    if(left<n && a[left]>a[largest])
        largest=left;
    
    if(right<n && a[right]>a[largest])
        largest=right;
    
    if(ind!=largest)
    {
        swap(a[ind],a[largest]);
        heapify(a,largest,n);
    }
}

void heapSort(int a[],int n)
{
    //building the heap from bottom O(n)
    for(int i=n/2-1;i>=0;i--)
        heapify(a,i,n); 
    
    //sort elements using max heap formed above O(n*log(n))
    for(int i=n-1;i>=0;i--)
    {
        swap(a[0],a[i]);
        heapify(a,0,i);
    }
}

int main()
{
	int n;
    cin>>n;
    int a[n];
    
    for(int i=0;i<n;i++)
        cin>>a[i];
    
    heapSort(a,n);
    
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}