/*
Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices's such that for every directed edge u-->v, vertex u comes before v 
in the ordering. 
Topological Sorting for a graph is not possible if the graph is not a DAG (DFS give wrong answer if graph is not DAG).
A DAG G has at least one vertex with in-degree 0 and one vertex with out-degree 0.
O(e+v) S(bm) space complexity, where b is the branching factor of the tree and m is the maximum length of any path
*/

/*
code is written assuming that given graph is DAG
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int li;

vector<li> vec[100000];
vector<li> topOrder;
li vis[100000]={0};
stack<li> st;

void usingDFS(li i)
{
	vis[i]=1;
	for(li j=0;j<vec[i].size();j++)
	{
		if(!vis[vec[i][j]])
			usingDFS(vec[i][j]);
	}	
    
    st.push(i); 
}

void usingKahnsAlgo(li v)
{
    li i,j;
	vector<li> inorder(v+1,0);
	for(i=1;i<=v;i++)
	{
		for(j=0;j<vec[i].size();j++)
			inorder[vec[i][j]]++;
	}

	queue<li> que;
	for(i=1;i<=v;i++)
	{
		if(!inorder[i])
			que.push(i);
	}

	while(!que.empty())
	{
    	i=que.front();
    	que.pop();
    	topOrder.push_back(i);
    	for(j=0;j<vec[i].size();j++)
    	{
    		inorder[vec[i][j]]--;
    		if(inorder[vec[i][j]]==0)
    			que.push(vec[i][j]);
    	}
	}
}

int main()
{
	li i,x,y,v,e;
	cin>>v>>e;
	for(i=0;i<e;i++)
	{
		cin>>x>>y;
		vec[x].push_back(y); //directed graph
	}
	
	//using DFS
	for(i=1;i<=v;i++)
	{
		if(!vis[i])
			usingDFS(i);	
	}

	while(!st.empty())
	{
		cout<<st.top()<<" ";
		st.pop();
	}	
	
	cout<<"\n";
	//using Kahn’s algorithm
	usingKahnsAlgo(v);
	if(topOrder.size()==v)
	{
		for(i=0;i<topOrder.size();i++)
			cout<<topOrder[i]<<" ";	
	}
	else
		cout<<"cycle is present in given DAG";
	
	return 0;
}



