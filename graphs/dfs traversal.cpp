/*
DFS traversal 
O(e+v) S(bm) space complexity, where b is the branching factor of the tree and m is the maximum length of any path 
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int li;

vector<li> vec[100001];
li vis[100001]={0};

void dfsByRecursion(li i)
{
	vis[i]=1; 
	cout<<i<<" ";
	for(li j=0;j<vec[i].size();j++)
	{
		if(!vis[vec[i][j]])
			dfsByRecursion(vec[i][j]);
	}		
}

void dfsByIteration(li i)
{
	stack<li> st;
	li temp,j;
	st.push(i);
	vis[i]=1;
	
	while(!st.empty())
	{
		temp=st.top();
		cout<<temp<<" ";
		st.pop();
		
		for(j=0;j<vec[temp].size();j++)
		{
			if(!vis[vec[temp][j]])
			{
				st.push(vec[temp][j]);
				vis[vec[temp][j]]=1;
			}
		}		
	}			
}

int main()
{
	li i,v,e,x,y;
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
			dfsByRecursion(i);
	}

	for(i=1;i<=v;i++)
		vis[i]=0;
	
    cout<<"\n";
	for(i=1;i<=v;i++)
	{
		if(!vis[i])
			dfsByIteration(i);
	}

	return 0;
}


