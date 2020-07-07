/*
The Bellman–Ford algorithm is an algorithm that computes shortest paths from a single source vertex to all of the other vertices
It's a example of dynammic programming
O(v*e) S(v)
https://www.geeksforgeeks.org/bellman-ford-algorithm-dp-23
*/

#include<bits/stdc++.h>
#define INF 1e15
using namespace std;
typedef long long int li;

vector< pair<li,li> > vec[100000];
vector<li> dist(100000,INF);

void bellmanFord(li s,li vertex)
{
	li i,j,k,u,v,w,chk;
	dist[s]=0;
	for(k=1;k<=vertex-1;k++)
	{
		for(i=1;i<=vertex;i++)
		{
			u=i;
			for(j=0;j<vec[i].size();j++)
			{
				v=vec[i][j].fir;  w=vec[i][j].sec;
				if(dist[u]+w<dist[v])
					dist[v]=dist[u]+w;
			}	
		}	
	}
	
	chk=0;
	for(i=1;i<=vertex;i++)
	{
		u=i;  
		for(j=0;j<vec[i].size();j++)
		{
			v=vec[i][j].fir;  w=vec[i][j].sec;
			if(dist[u] + w < dist[v])
			{
				cout<<"negative cycle exist";
				chk=1;
				break;	
			}	
		}	

		if(chk==1)
			break;
	}
}

int main()
{
	li i,v,e,x,y,w,s;
	cin>>v>>e;
	for(i=0;i<e;i++)
	{
		cin>>x>>y>>w;
		vec[x].push_back(make_pair(y,w));
		vec[y].push_back(make_pair(x,w));
	}
	
	cin>>s;
	bellmanFord(s,v);
	
	for(i=1;i<=v;i++)
		cout<<i<<" "<<dist[i]<<"\n";	

	return 0;
}


