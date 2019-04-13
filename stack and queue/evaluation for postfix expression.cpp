/*
expression evaluation of given postfix expression (reverse polish notation) 
this is similiar to expression evaluation of prefix expression (polish notation) - in this case start from last and do the same
(5 − 6) * 7 = 56-7* //postfix   
(5 − 6) * 7 = *−567 //prefix 
O(n) S(n)
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,tp;
    string str;
    vector<string> A;
    
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>str;
        A.push_back(str);
    }
    
    //assuming that given expression is post expression 
    stack<int> st;
    int x,y;
    for(i=0;i<n;i++)
    {
        if(A[i]=="+")
        {
            x=st.top(); st.pop(); y=st.top(); st.pop();
            st.push(y+x);
        }
        else if(A[i]=="-")
        {
            x=st.top(); st.pop(); y=st.top(); st.pop();
            st.push(y-x);
        }
        else if(A[i]=="*")
        {
            x=st.top(); st.pop(); y=st.top(); st.pop();
            st.push(y*x);
        }
        else if(A[i]=="/")
        {
            x=st.top(); st.pop(); y=st.top(); st.pop();
            st.push(y/x);
        }
        else
            st.push(stoi(A[i]));
    }
    
    cout<<st.top();
}
