/*
cycle detection in undirected graph
dfs O(v+e) S(b*m)
union find O(v + e (log v)) S(v)
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int li;

li parent[100000],sz[100000];
pair<li,li> pa[100000];

vector<li> vec[100000];
li vis[100000]={0};
bool flag;

void initialize(li v)
{
	for(li i=1;i<=v;i++)
	{
		parent[i]=i;
		sz[i]=1;
	}
}

li root(li x)
{
	while(parent[x]!=x)
	{
		x=parent[x];
	}

	return x;
}

void weightedUnion(li x,li y)
{
	li p=root(x);
	li q=root(y);

	if(sz[p]<sz[q])
	{
		parent[p]=parent[q];
		sz[q]=sz[q]+sz[p];
	}
	else
	{
		parent[q]=parent[p];
		sz[p]=sz[p]+sz[q];
	}
}

li find(li x,li y)
{
	if(root(x)==root(y))
		return true;
	else
		return false;
}

void usingDFS(li i,li parent) //here is child
{
	vis[i]=1;  
	
	for(li j=0;j<vec[i].size();j++)
	{
		if(vis[vec[i][j]] && vec[i][j]!=parent)
			flag=true;
			
		if(!vis[vec[i][j]])
			usingDFS(vec[i][j],i);
	}			
}

int main()
{
	li i,v,e,x,y;
	cin>>v>>e;

	for(i=0;i<e;i++)
	{
		cin>>x>>y;
		pa[i]=make_pair(x,y);
		vec[x].push_back(y); 
		vec[y].push_back(x); //undirected graph
    }

	//union find
	initialize(v);
	flag=false;
	for(i=0;i<e;i++)
	{
		x=pa[i].first;
		y=pa[i].second;
		
		if(!find(x,y))
			weightedUnion(x,y);
		else
		{
			flag=true;
			break;
		}
	}

	if(flag)
		cout<<1;
	else 
		cout<<0;

	//DFS
	flag=false;
	for(i=1;i<=v;i++)
	{
		if(!vis[i])
			usingDFS(i,0);	
	}

	if(flag)
		cout<<endl<<1;
	else 
		cout<<endl<<0;

	return 0;
}


