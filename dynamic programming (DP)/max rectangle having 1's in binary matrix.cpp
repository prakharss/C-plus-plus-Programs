/*
maximum rectangular sub-matrix having all 1's in a binary matrix
O(R*C) S(R*C)
*/

#include<bits/stdc++.h>
using namespace std;

int maxAreaHistogram(int hist[],int n)
{
    int i,maxArea;
    stack<int> st;
    
    i=0; maxArea=0;
    while(i<n)
    {
        if(st.empty() || hist[st.top()]<=hist[i])
        {
            st.push(i);
            i++;
        }
        else
        {
            int tp=st.top();
            st.pop();
            
            if(st.empty())
                maxArea=max(maxArea,hist[tp]*i);
            else
                maxArea=max(maxArea,hist[tp]*(i-st.top()-1));
        }
    }
    
    while(!st.empty())
    {
        int tp=st.top();
        st.pop();

        if(st.empty())
            maxArea=max(maxArea,hist[tp]*i);
        else
            maxArea=max(maxArea,hist[tp]*(i-st.top()-1));
    }
    
    return maxArea;
}

int main()
{
    int R,C,i,j,maxArea;
    cin>>R>>C;
    int matrix[R][C];
    int temp[R][C];
    
    for(i=0;i<R;i++)
        for(j=0;j<C;j++)
            cin>>matrix[i][j];
    
    maxArea=maxAreaHistogram(matrix[0],C);
    for(i=1;i<R;i++)
    {
        for(j=0;j<C;j++)
        {
            if(matrix[i][j])
                matrix[i][j]=matrix[i][j]+matrix[i-1][j];
        }
        
        maxArea=max(maxArea,maxAreaHistogram(matrix[i],C));
    }  
        
    cout<<maxArea;
}
