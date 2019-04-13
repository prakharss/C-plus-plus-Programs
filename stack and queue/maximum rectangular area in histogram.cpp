/*
maximum rectangular area in histogram
logic used here is same as of stock span problem
basically we can find (next or previous) maximum and minimum of a number in an array
in stock span we just needed previous maximum value of every value and here we need previous and next minimum value of every number 
one more implementation in IB
O(n) S(n)
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,mx;
    cin>>n;
    int a[n];
    
    for(i=0;i<n;i++)
        cin>>a[i];
    
    stack<int> st; 
    mx=0; i=0;  
    while(i<n)
    {
        if(st.empty() || a[st.top()]<=a[i])
        {
            st.push(i);
            i++;
        }
        else
        {
            int tp=st.top();
            st.pop();
            
            if(st.empty())
                mx=max(mx,a[tp]*i);
            else
                mx=max(mx,a[tp]*(i-st.top()-1));  //rightIndex=i and leftIndex=st.top();
        }
    }
    
    while(!st.empty())
    {
        int tp=st.top();
        st.pop();

        if(st.empty())
            mx=max(mx,a[tp]*i);
        else
            mx=max(mx,a[tp]*(i-st.top()-1));
    }
        
	cout<<mx;
    return 0;
}
