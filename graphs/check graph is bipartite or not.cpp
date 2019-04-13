/*
check graph is bipartite or not
O(e+v) S(bm) space complexity, where b is the branching factor of the tree and m is the maximum length of any path
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int li;

vector<li> vec[100001];
li vis[100001]={0},color[100001]={0};
bool flag;

void usingDFS(li i)
{
    vis[i]=1; 
    for(li j=0;j<vec[i].size();j++)
    {
        if(color[i]==1)
        {
            if(color[vec[i][j]]==0 || color[vec[i][j]]==2)
                color[vec[i][j]]=2;
            else if(color[vec[i][j]]==1)
                flag=false;
        }
        else if(color[i]==2)
        {
            if(color[vec[i][j]]==0 || color[vec[i][j]]==1)
                color[vec[i][j]]=1;
            else if(color[vec[i][j]]==2)
                flag=false;
        }
        
        if(!vis[vec[i][j]])
            usingDFS(vec[i][j]);
    }       
}

void usingBFS(li i)
{
    queue<li> que;
    li temp,j;
    que.push(i);
    vis[i]=1;
    
    while(!que.empty())
    {
        i=que.front();
        que.pop();
        
        for(j=0;j<vec[i].size();j++)
        {
            if(color[i]==1)
            {
                if(color[vec[i][j]]==0 || color[vec[i][j]]==2)
                    color[vec[i][j]]=2;
                else if(color[vec[i][j]]==1)
                    flag=false;
            }
            else if(color[i]==2)
            {
                if(color[vec[i][j]]==0 || color[vec[i][j]]==1)
                    color[vec[i][j]]=1;
                else if(color[vec[i][j]]==2)
                    flag=false;
            }
            
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
    li i,v,e,x,y;
    cin>>v>>e;

    for(li i=0;i<e;i++)
    {
        cin>>x>>y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    
    //DFS
    flag=true;
    for(i=1;i<=v;i++)
    {
        if(!vis[i])
        {
            color[i]=1;
            usingDFS(i);
        }
    }
    
    if(flag)
        cout<<1;
    else 
        cout<<0;
    
    for(i=1;i<=v;i++)
    {
        vis[i]=0;
        color[i]=0;
    }
    
    //BFS
    flag=true;
    for(i=1;i<=v;i++)
    {
        if(!vis[i])
        {
            color[i]=1;
            usingBFS(i);
        }   
    }
    
    if(flag)
        cout<<endl<<1;
    else 
        cout<<endl<<0;
    
    return 0;
}


