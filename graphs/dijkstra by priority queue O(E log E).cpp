/*
it's a greedy algorithm
O(e log e)
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int li;

priority_queue<pair<li,li>, vector<pair<li,li> >, greater<pair<li,li> > > pq;
vector<pair<li,li> > vec[100000];
li vis[100000]={0};
vector<li> dist(100000,INF);

void dijkstra(li s)
{
	li cnt,u,v,w,i;
	pq.push(make_pair(0,s));  dist[s]=0;
	cnt=0;
	while(!pq.empty()) //while(cnt<vtx) - this will also work
	{
		while(!pq.empty() && vis[(pq.top()).second])
			pq.pop();
		
		if(pq.empty())
			break;
		
		u=(pq.top()).second;
		vis[u]=1; cnt++;
		pq.pop();
		
		for(i=0;i<vec[u].size();i++)
		{
			v=vec[u][i].first;  w=vec[u][i].second;
			if(dist[u]+w<dist[v] && !vis[v])
			{
				dist[v]=dist[u]+w;
				pq.push(make_pair(dist[v],v));
			}	
		}		
	}	
}

int main()
{
	li i,x,y,w,s;
	cin>>v>>e;
	for(i=0;i<e;i++)
	{
		cin>>x>>y>>w;
		vec[x].push_back(make_pair(y,w));
		vec[y].push_back(make_pair(x,w));
	}
	
	cin>>s;
	dijkstra(s);
	
	for(i=1;i<=v;i++)
		cout<<i<<" "<<dist[i]<<"\n";

	return 0;	
}




/*
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
priority_queue<pair<li,li>, vector<pair<li,li> >, greater<pair<li,li> > > pq;
vector<li> dist(10000,INF);
li vtx,edge;

void dijkstra(li s)
{
	li cnt,u,v,w,i;
	pq.push(make_pair(0,s));  dist[s]=0;
	cnt=0;
	while(cnt<vtx)                              
	{
		while(vis[(pq.top()).sec])
			pq.pop();
		
		u=(pq.top()).sec;
		vis[u]=1; cnt++;
		pq.pop();
		
		for(i=0;i<vec[u].size();i++)
		{
			v=vec[u][i].fir;  w=vec[u][i].sec;
			if(dist[u]+w<dist[v] && !vis[v])
			{
				dist[v]=dist[u]+w;
				pq.push(make_pair(dist[v],v));
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
	
	cin>>s;
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

*/

