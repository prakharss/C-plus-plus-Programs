/*
The Floyd Warshall Algorithm is for solving the All Pairs Shortest Path problem
It's a example of dynammic programming
O(v^3) S(v^2)
*/

#include<bits/stdc++.h>
#define INF 1e15
using namespace std;
typedef long long int li;

vector<pair<li,li> > vec[100000];
li dist[1000][1000];


void floydWarshall(li v)
{
	li i,j,k;
	/* 
		Add all vertices one by one to  
	    the set of intermediate vertices.  
	    ---> Before start of this iteration,  
	    we have shortest distances between all  
	    pairs of vertices such that the  
	    shortest distances consider only the  
	    vertices in set {0, 1, 2, .. k-1} as 
	    intermediate vertices.  
	    ----> After the end of this iteration,  
	    vertex no. k is added to the set of  
	    intermediate vertices and the set becomes {0, 1, 2, .. k} 
    */
	for(k=1;k<=v;k++)
	{
		//i is source vertex
		for(i=1;i<=v;i++)
		{
			//j is destination vertex
			for(j=1;j<=v;j++)
			{
				if(dist[i][k]+dist[k][j]<dist[i][j])
					dist[i][j]=dist[i][k]+dist[k][j];
			}
		}
	}
}

int main()
{
	li i,j,v,e,x,y,w;
	cin>>v>>e;
	
	for(i=1;i<=v;i++)
	{
		for(j=1;j<=v;j++)
		{
			if(i==j)
				dist[i][j]=0;
			else
				dist[i][j]=INF;
		}		
	}
	
	for(i=0;i<e;i++)
	{
		cin>>x>>y>>w;
		dist[x][y]=w;  
		dist[y][x]=w;
	}
	
	floydWarshall(v);	
	
	for(i=1;i<=v;i++)
	{
		for(j=1;j<=v;j++)
		{
			if(dist[i][j]==INF)
				cout<<i<<" "<<j<<" -1\n";
			else
				cout<<i<<" "<<j<<" "<<dist[i][j]<<"\n";	
		}			
	}

	return 0;	
}

