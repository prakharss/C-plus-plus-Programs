/*
In a candy store there are N different types of candies available and the prices of all the N different types of candies are provided. 
There is also an attractive offer by candy store. We can buy a single candy from the store and get at-most K other candies (all are different types) for free.

Find minimum amount of money we have to spend to buy all the N different candies.
Find maximum amount of money we have to spend to buy all the N different candies.
In both the cases we must utilize the offer and get maximum possible candies back.
*/

/*
O(n log(n))
*/

#include <iostream>
using namespace std;
int main()
 {
      int n,m,i,j,k,T,t,u,v;
      cin>>T;         
      while(T--)
      {
         cin>>n>>k;
         int a[n],sum,cnt;
         for(i=0;i<n;i++)
         {
              cin>>a[i];
         }
         
         if((n % (k+1))==0)
         cnt = n/(k+1);
         else
         cnt = (n/(k+1))+1;
         sort(a,a+n);
         
         sum=0;
         for(i=0;i<cnt;i++)
         sum=sum+a[i];
         cout<<sum<<" ";
         
         reverse(a,a+n);
         sum=0;
         for(i=0;i<cnt;i++)
         sum=sum+a[i];
         cout<<sum<<"\n";
       } 
}