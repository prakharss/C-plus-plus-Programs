/*
given an array A of sorted integers and another non negative integer k.
find if there exists 2 indices i and j such that A[i]-A[j]=k and i!=j.

can be solved with binary search O(n*log(n))
but using 2 pointer it can be solved O(n)
O(n) S(1)
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,chk,diff,j;
    cin>>n>>diff;
    int A[n];
    
    for(i=0;i<n;i++)
        cin>>A[i];
     
    i=0; j=1; chk=0;
    while(i<n && j<n)
    {
        if(i==j)
            j++;
            
        if(A[j]-A[i]<diff)
            j++;
        else if(A[j]-A[i]>diff)
            i++;
        else if(A[j]-A[i]==diff)
        {
            chk=1;
            break;
        }
    }
    
    if(chk)
        cout<<"yes";
    else
        cout<<"no";
}


