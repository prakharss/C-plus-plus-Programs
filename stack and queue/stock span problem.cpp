/*
stock span problem
The stock span problem is a financial problem where we have a series of n daily price quotes for a 
stock and we need to calculate span of stock’s price for all n days. 
The span Si of the stock’s price on a given day i is defined as the maximum number of consecutive 
days just before the given day, for which the price of the stock on the current day is less than
or equal to its price on the given day.
For example, if an array of 7 days prices is given as {100, 80, 60, 70, 60, 75, 85}, then the span 
values for corresponding 7 days are {1, 1, 1, 2, 1, 4, 6}
geeks implementation is different
O(n) S(n)
*/

/*
One important thing in below solution is:
all the values are in decreasing order in stack
*/

// a linear time solution for stock span problem 
#include <iostream> 
#include <stack> 
using namespace std; 
  
void calculateSpan(int price[], int n, int S[]) 
{  
   stack<int> st; 
   st.push(0); 
  
   // Span value of first element is always 1 
   S[0] = 1; 
  
   // Calculate span values for rest of the elements 
   for (int i = 1; i < n; i++) 
   { 
      // Pop elements from stack while stack is not  
      // empty and top of stack is smaller than  
      // price[i] 
      while (!st.empty() && price[st.top()] <= price[i]) 
         st.pop(); 
  
      // If stack becomes empty, then price[i] is 
      // greater than all elements on left of it, 
      // i.e., price[0], price[1],..price[i-1].  Else 
      // price[i] is greater than elements after  
      // top of stack 
      S[i] = (st.empty())? (i + 1) : (i - st.top()); 
  
      // Push this element to stack 
      st.push(i); 
   } 
} 
  
// A utility function to print elements of array 
void printArray(int arr[], int n) 
{ 
    for (int i = 0; i < n; i++) 
      cout << arr[i] << " "; 
} 
  
// Driver program to test above function 
int main() 
{ 
    int price[] = {10, 4, 5, 90, 120, 80}; 
    int n = sizeof(price)/sizeof(price[0]); 
    int S[n]; 
  
    // Fill the span values in array S[] 
    calculateSpan(price, n, S); 
  
    // print the calculated span values 
    printArray(S, n); 
  
    return 0; 
}


/*
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i;
    cin>>n;
    int arr[n],ans[n];
    stack<int> st;
    
    for(i=0;i<n;i++)
        cin>>arr[i];
    
    i=0;
    while(i<n)
    {
        if(st.empty() || arr[st.top()]>=arr[i])
        {
            st.push(i);
            i++;
        }
        else
        {
            int tp=st.top();
            //cout<<tp<<" ";
            st.pop();
            
            if(!st.empty())
                ans[tp]=tp-st.top();
            else
                ans[tp]=tp+1;
        }
    }
    
    while(!st.empty())
    {
        int tp=st.top();
        //cout<<tp<<" ";
        st.pop();
        
        if(!st.empty())
            ans[tp]=tp-st.top();
        else
            ans[tp]=tp+1;
    }
        
	for(i=0;i<n;i++)
        cout<<ans[i]<<" ";
}
*/