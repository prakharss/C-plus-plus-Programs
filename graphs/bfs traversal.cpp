/*
bfs traversal
O(e+v) S(bm) space complexity, where b is the branching factor of the tree and m is the maximum length of any path 
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int li;

vector<li> vec[100000];
li vis[100000]={0};

void bfs(li i)
{
	queue<li> que;
	li j;
	que.push(i);
	vis[i]=1;
	
	while(!que.empty())
	{
		i=que.front();
		cout<<i<<" ";
		que.pop();
		
		for(j=0;j<vec[i].size();j++)
		{
			if(!vis[vec[i][j]])
			{
				que.push(vec[i][j]);
				vis[vec[i][j]]=1;
			}
		}		
	}			
}

int main()
{
	li i,v,e,x,y;;
	cin>>v>>e;
	for(i=0;i<e;i++)
	{
		cin>>x>>y;
		vec[x].push_back(y);
		vec[y].push_back(x);
	}
	
	for(i=1;i<=v;i++)
	{
		if(!vis[i])
			bfs(i);	
	}

	return 0;
}



