/*
path of a rat in a maze
A Maze is given as N*N binary matrix of blocks where source block is the upper left most block i.e., maze[0][0] and 
destination block is lower rightmost block i.e., maze[N-1][N-1]. A rat starts from source and has to reach destination. The rat can move
only in two directions: forward and down.
this gives all solutions but single solution can be implemented using return statement (refer geeksforgeeks)
O(C(m+n-2,n-1)) S(n*m)
*/

#include<bits/stdc++.h>
#define N 1000
using namespace std;
typedef long long int li;

li maze[N][N],mazeSolution[N][N]={0};
li n,m,cnt=0;

void printPath()
{
    cout<<cnt+1<<"\n";
	for(li i=0;i<n;i++)
	{
		for(li j=0;j<m;j++)
			cout<<mazeSolution[i][j]<<" ";
		cout<<"\n";
	}
    
    cout<<"\n";
    cnt++;
}

bool isSafe(li i,li j)
{
	return (i>=0 && i<n && j>=0 && j<m && maze[i][j]);
}

void findAllPaths(li i,li j)
{
	if(!isSafe(i,j))
		return ;

	if(i==n-1 && j==m-1)
	{
		mazeSolution[i][j]=1;
		printPath();	
		mazeSolution[i][j]=0; //backtrack
	}
	else
	{
		mazeSolution[i][j]=1;
		findAllPaths(i,j+1);
		findAllPaths(i+1,j);
		mazeSolution[i][j]=0; //backtrack
	}
}

int main()
{
	li i,j;
	cin>>n>>m;

	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			cin>>maze[i][j];
    
    findAllPaths(0,0);
	
    if(!cnt)
		cout<<-1;	
}


