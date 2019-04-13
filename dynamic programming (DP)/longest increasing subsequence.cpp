/*
to find length of longest strictly increasing subsequence 
O(n^2) S(1)

there is one more solution which is O(n log(n)) - https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int i,j,n;
	cin>>n;
	int arr[n];
    vector<int> len(n,1); //to initialise vector of size n with value of 1
	
	for(i=0;i<n;i++)
		cin>>arr[i];
	
	for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(arr[i]>arr[j] && len[i]<len[j]+1)
                len[i]=len[j]+1;
        }
    }
	
    
    /*for(i=0;i<n;i++)
        cout<<len[i]<<" ";
    cout<<"\n";*/
    
	cout<<*max_element(len.begin(),len.end());
	return 0;
}


