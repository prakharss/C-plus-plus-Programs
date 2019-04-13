/*
cycle detection in a directed graph
O(e+v) S(bm) space complexity, where b is the branching factor of the tree and m is the maximum length of any path
*/

/*
in DFS we are keeping track of all vertices which are inside the stack and while traversing if we find any vertex which is already in stack, it means
cycle exists in the given graph 
*/

/*
ryt now don't know the logic behind Kahns Algorithm
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int li;

vector<li> vec[100001];
vector<li> topOrder;
li chk[100001]={0};
li vis[100001]={0};
bool flag;

void usingDFS(li i)
{
	vis[i]=1; chk[i]=1;
	for(li j=0;j<vec[i].size();j++)
	{
		if(chk[vec[i][j]])
			flag=true;
			
		if(!vis[vec[i][j]])
			usingDFS(vec[i][j]);			
	}

	chk[i]=0;			
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
    	topOrder.push_back(i);
    	for(j=0;j<vec[i].size();j++)
    	{
    		inorder[vec[i][j]]--;
    		if(inorder[vec[i][j]]==0)
    			que.push(vec[i][j]);
    	}
        
        que.pop();
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
	
	//DFS
	flag=false;
	for(i=1;i<=v;i++)
	{
		if(!vis[i])
			usingDFS(i);	
	}

	if(flag)
		cout<<1;
	else 
		cout<<0;
    
    //Kahns Algo
    cout<<"\n";
	usingKahnsAlgo(v); 
	if(topOrder.size()!=v)
		cout<<1;
	else
		cout<<0;

	return 0;
}


