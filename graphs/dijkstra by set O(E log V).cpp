/*
https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-set-in-stl/
O(E * log(E)) - maximum E edges in priority queue
1)  Whenever distance of a vertex is reduced, we add one more instance of vertex in priority_queue. Even if there are multiple instances,
    we only consider the instance with minimum distance and ignore other instances.
2)  The time complexity remains O(ELogV)) as there will be at most O(E) vertices in priority queue and O(Log E) is same as O(Log V)
	it means actual time complexity is O(ElogE) as there can atmost O(E) vertces in priority queue
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int li;
#define cc continue
#define bb break
#define rr return
#define W while
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define INF 0x3f3f3f3f
//vector<li> vec;
//pair<li,li> pa[1000000];
//string str1,str2;
//li a[1000000];
vector< pair<li,li> > vec[10000];
li vis[10000]={0};
set<pair<li,li> > st;
set<pair<li,li> > :: iterator it_st;
vector<li> dist(10000,INF);
li vtx,edge;

void dijkstra(li s)
{
	li cnt,i,u,v,w;
	st.insert(make_pair(0,s));   dist[s]=0;
	cnt=0;
	while(cnt<vtx)
	{
	    it_st=st.begin();
		u=(*it_st).sec;
		vis[u]=1;  cnt++; //cout<<u<<" ";
		st.erase(st.begin());  
		
		for(i=0;i<vec[u].size();i++)
		{   //cout<<"hi";
			v=vec[u][i].fir;
			w=vec[u][i].sec;
			if(dist[u]+w<dist[v] && !vis[v])
			{
				if(dist[v]!=INF)
					st.erase(st.find(make_pair(dist[v],v)));
				
				dist[v]=dist[u]+w;
				st.insert(make_pair(dist[v],v));
			}		
		}	
	}	
}

void solve_this()
{
	li i,x,y,w,s;
	cin>>vtx>>edge;
	for(i=0;i<edge;i++)
	{
		cin>>x>>y>>w;
		vec[x].push_back(make_pair(y,w));
		vec[y].push_back(make_pair(x,w));
	}
	
	cin>>s;  //cout<<"222222";
	dijkstra(s);
	
	for(i=1;i<=vtx;i++)
		cout<<i<<" "<<dist[i]<<"\n";	
}

int main()
{
ios_base::sync_with_stdio(false); cin.tie(0);
solve_this();
rr 0;
}


