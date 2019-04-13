/*
maximum square sub-matrix having all 1's in a binary matrix
temp[i][j] is the maximum size of submatrix having (i,j) co-ordinate as bottom right corner
O(R*C) S(R*C)
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int R,C,i,j,maxSize;
    cin>>R>>C;
    int matrix[R][C];
    int temp[R][C];
    
    for(i=0;i<R;i++)
        for(j=0;j<C;j++)
            cin>>matrix[i][j];
 
    for(i=0;i<R;i++)
    {
        for(j=0;j<C;j++)
        {
            if(i==0 || j==0)
                temp[i][j]=matrix[i][j];
            else if(matrix[i][j]==0)
                temp[i][j]=0;
            else    
                temp[i][j]=1+min(temp[i-1][j-1],min(temp[i][j-1],temp[i-1][j]));   
        }
    }
    
    maxSize=0;
    for(i=0;i<R;i++)
        for(j=0;j<C;j++)
            maxSize=max(maxSize,temp[i][j]);    
        
    cout<<maxSize;
}
