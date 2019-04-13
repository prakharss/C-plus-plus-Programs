/*
Soduko solver
Given a partially filled 9×9 2D array ‘grid[9][9]’, the goal is to assign digits (from 1 to 9) to the empty cells so that every row, column
and subgrid of size 3×3 contains exactly one instance of the digits from 1 to 9. 
this gives a single solution and we can easily write for multiple solutions
O(9^81) S(1)
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int li;

li board[9][9];

void printSolution()
{
	for(li i=0;i<9;i++)
	{
		for(li j=0;j<9;j++)
			cout<<board[i][j]<<" ";
		cout<<"\n";
	}
}

bool UsedInRow(int row,int num)
{
    for (int col=0;col<9;col++)
        if (board[row][col]==num)
            return true;
    return false;
}

bool UsedInCol(int col,int num)
{
    for (int row=0;row<9;row++)
        if (board[row][col]==num)
            return true;
    return false;
}

bool UsedInBox(int boxStartRow,int boxStartCol,int num)
{
    for (int row=0;row<3;row++)
        for (int col=0;col<3;col++)
            if (board[row+boxStartRow][col+boxStartCol]==num)
                return true;
    return false;
}

bool isSafe(int row,int col,int num)
{
    return !UsedInRow(row,num) && !UsedInCol(col,num) && !UsedInBox(row-row%3,col-col%3,num);
}

li findX()
{
	for(li i=0;i<9;i++)
	{
		for(li j=0;j<9;j++)
		{
			if(!board[i][j])
				return i;
		}
	}
	return -1;
}

li findY()
{
	for(li i=0;i<9;i++)
	{
		for(li j=0;j<9;j++)
		{
			if(!board[i][j])
				return j;
		}
	}
	return -1;
}

bool soduko(li i,li j)
{
	li x,y;
	if(i==-1 && j==-1)
	{
		printSolution();
		return true;
	}
	
	for(li k=1;k<=9;k++)
	{
		if(isSafe(i,j,k))
		{
			board[i][j]=k;
			
			x=findX(); y=findY(); //find first unassigned coordinates
			if(soduko(x,y))
				return true;

			board[i][j]=0;
		}	
	}	
	
	return false;	
}

int main()
{
	li i,j;

	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
			cin>>board[i][j];
	}

	x=findX(); y=findY(); //find first unassigned coordinates
	soduko(x,y);
	
	return 0;
}




/*
3 0 6 5 0 8 4 0 0
5 2 0 0 0 0 0 0 0
0 8 7 0 0 0 0 3 1
0 0 3 0 1 0 0 8 0
9 0 0 8 6 3 0 0 5
0 5 0 0 9 0 6 0 0
1 3 0 0 0 0 2 5 0
0 0 0 0 0 0 0 7 4
0 0 5 2 0 6 3 0 0     
*/
