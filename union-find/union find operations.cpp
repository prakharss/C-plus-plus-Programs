/*
union find operation (for undirected graph)
if there are m (union or find) operation on n vertices 
then 
O(n + m (log n)) S(n)
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int li;

li parent[100000],sz[100000];
li n;

//O(V)
void initialize(li nodes)
{
    for(li i=1;i<=nodes;i++)
	{
    	parent[i]=i;
    	sz[i]=1;
	}
}

//O(log(V)) 
li root(li x)
{
    while(parent[x]!=x) //if something is root (let say x), it means parent[x]=x 
    { 
        //Path Compression Step
        //To make complexity better than O(log(V)) for union and find operation
        
        //parent[x]=parent[parent[x]] 
        x=parent[x]; //going up one by one untill we reach parent
    }

    return x;
}

//O(log(V))
//only root elements change their sizes
void weightedUnion(li x,li y)
{
    li p=root(x);
    li q=root(y);
    //Weighted union i.e union by rank to minimize the height of the component 
    //And this makes complexity of weighted union to be logarithmic
    if(sz[p]<sz[q]) 
    {
    	parent[p]=q; //parent[p]=parent[q]; as parent[q]=parent[q] 
    	sz[q]=sz[q]+sz[p]; //only root size changes 
	} 
	else
	{
		parent[q]=p; //parent[q]=parent[p]; as parent[p]=p
    	sz[p]=sz[p]+sz[q];
	}
}

//O(log(n))
bool find(li x,li y) {
	if(root(x)==root(y))
	   return true;
	else
	   return false;	
}

int main()
{
	li x,y,chk,i,m;
    cin>>n;
    initialize(n);
    		
    //x and y are vertices connecting an edge
	cin>>x>>y;
	if(!find(x,y))
	   weightedUnion(x,y);

    return 0;	
}









