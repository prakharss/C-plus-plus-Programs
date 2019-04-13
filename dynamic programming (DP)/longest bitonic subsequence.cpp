/*
longest bitonic subsequence
subsequence of arr[] is called Bitonic if it is first increasing, then decreasing.
O(n^2) S(1)
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,j,n;
    cin>>n;
    int arr[n];
    
    for(i=0;i<n;i++)
        cin>>arr[i];
    
    vector<int> frontLen(n,1);
    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
           if(arr[i]>arr[j] && frontLen[i]<frontLen[j]+1)
               frontLen[i]=frontLen[j]+1;
        }
    }
    
    vector<int> backLen(n,1);
    for(i=n-2;i>=0;i--)
    {
        for(j=n-1;j>i;j--)
        {
           if(arr[i]>arr[j] && backLen[i]<backLen[j]+1)
               backLen[i]=backLen[j]+1;
        }
    }
    
    int len=0;
    for(i=0;i<n;i++)
        len=max(len,frontLen[i]+backLen[i]-1);    
    
    cout<<len<<"\n";
    return 0;
}

