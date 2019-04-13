/*
https://www.geeksforgeeks.org/majority-element/
using moores voting algotrithm
*/

#include<bits/stdc++.h>
using namespace std;

bool isMajorityElement(vector<int> &A, int majorityElement)
{
    int cnt=0,n=A.size();
    for(int i=0;i<n;i++)
    {
        if(A[i]==majorityElement)
            cnt++;
    }
    
    if(cnt>(n/2))
        return true;
    else
        return false;
}

int main()
{
    int n,i,majorityElement,count,t;
    cin>>n;
    vector<int> A;
    
    for(i=0;i<n;i++)
    {
        cin>>t;
        A.push_back(t);
    }
    
    majorityElement=A[0]; count=1;
    for(i=1;i<n;i++)
    {
        if(A[i]==majorityElement)
            count++;
        else
            count--;
        
        if(count==0)
        {
            majorityElement=A[i];
            count=1;
        }
    }
    
    if(isMajorityElement(A,majorityElement))
    cout<<majorityElement<<"\n";
    else
    cout<<"-1";
}

/*
O(n)
S(1) 
*/