/*
N Queen is the problem of placing N chess queens on an N×N chessboard so that no two queens attack each other
this gives all solutions but single solution can be implemented using return statement (see the comments on code)
T(n) = n*T(n-1) + O(n^2) which translates to O(N!) time complexity in average
O(n!) S(1)
*/

#include<bits/stdc++.h>
using namespace std;

int board[1000][1000]={0};
int n,cnt=0;

void printBoard()
{
    cout<<cnt+1<<"\n";
    for(int row=0;row<n;row++)
    {
        for(int col=0;col<n;col++)
            cout<<board[row][col]<<" ";
        cout<<"\n";
    }
    cnt++; 
}

bool isSafe(int row,int col)
{
    int i,j;
    for(i=row-1,j=col-1;i>=0 && j>=0;i--,j--)
    {
        if(board[i][j])
            return false;
    }
        
    for(j=col-1;j>=0;j--)
    {
        if(board[row][j])
            return false;
    }
    
    for(i=row+1,j=col-1;i<n && j>=0;i++,j--)
    {
        if(board[i][j])
            return false;
    }
    
    return true;
}

void nQueenProblem(int col)
{
    if(col<n)
    {
        for(int row=0;row<n;row++)
        {
            if(isSafe(row,col))
            {
                board[row][col]=1;
                nQueenProblem(col+1);//if(nQueenProblem) return true; - for single solution
                board[row][col]=0;//backtrack step
            }
        }

        //return false
    }
    else
        printBoard();//return true
}

int main()
{
    cin>>n;
    nQueenProblem(0);
    
    if(!cnt)
        cout<<-1;
        
    return 0;
}