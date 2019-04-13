/*
if someone ask sort an array in O(n^2) then this algorithm comes in mind
in every loop we get lowest value at the starting  
O(n^2) S(1)
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
   int i,j,n;
   cin>>n;
   int a[n];

   for(i=0;i<n;i++)
      cin>>a[i];
         
   for(i=0;i<n-1;i++)
   {
      for(j=i+1;j<n;j++)
      {
         if(a[i]>a[j])
            swap(a[i],a[j]);
      }
   }
   
   for(i=0;i<n;i++)
      cout<<a[i]<<" ";
         
   return 0;
}
