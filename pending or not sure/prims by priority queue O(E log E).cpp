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
li vtx,edge;

li prims(li s)
{
	li cnt,u,v,w,i,ans=0;
	u=s;
	vis[u]=1;
	for(i=0;i<vec[u].size();i++)
	{
		v=vec[u][i].fir;
		w=vec[u][i].sec;
		pq.push(make_pair(w,v));
	}
	
	cnt=0;
	while(cnt<vtx-1)
	{
		if(vis[(pq.top()).sec])
			pq.pop();	

		u=pq.top().sec;  vis[u]=1;
		w=(pq.top()).fir;  
		ans=ans+w;
		pq.pop();
		for(i=0;i<vec[u].size();i++)
		{
			v=vec[u][i].fir;
			w=vec[u][i].sec;
			if(!vis[v])
				pq.push(make_pair(w,v));
		}
		cnt++;
	}
	return ans;
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
	
	cout<<prims(1);	
}

int main()
{
ios_base::sync_with_stdio(false); cin.tie(0);
solve_this();
rr 0;
}

