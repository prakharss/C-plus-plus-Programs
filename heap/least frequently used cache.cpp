#include<bits/stdc++.h>
using namespace std;
typedef long long int li;

void leastFrequentlyUsedCache(int c, vector<vector<int> > vec)
{
	int n,i,type,key,val,cnt,k;
	n=vec.size();
	
	priority_queue<pair<int, pair<int,int> > > pq; //has[key], (cnt, key)  - if has[key] is equal than it will check for oldest element
	map<int,int> mp;
	int has[100000]={0};
	
	cnt=100000;
	for(i=0;i<n;i++)
	{
		type=vec[i][0];
		if(type==1)
		{
			key=vec[i][1]; 
			has[key]++;
			
			if(mp.find(key)==mp.end())
				cout<<-1;
			else
				cout<<mp[key]<<"\n";
		}
		else
		{
			key=vec[i][1]; 
			has[key]++;
			val=vec[i][2];
			
			if(mp.size()==c)
			{
				k=pq.top().second.second;
				mp.erase(k);
				
				while(!pq.empty() && (pq.top().second.second)==k)
				{
					pq.pop();
				}
				
				pq.pop();
				has[k]=0;
			}
			
			pq.push(make_pair(has[key],make_pair(cnt,key)));
			cnt--;
			
			mp[key]=val;
		}
	}
}

int main()
{
	li n,i,val,key,capacity,type ;
	cin>>capacity;
	
	cin>>n;
	vector<int> vec;
	vector<vector<int> > vvec;
	
	for(i=0;i<n;i++)
	{
		cin>>type;
		vec.push_back(type);
		if(type==1)
		{
			cin>>key;
			vec.push_back(key);
		}
		else
		{
			cin>>key>>val;
			vec.push_back(key);
			vec.push_back(val);
		}
		
		vvec.push_back(vec);
		vec.clear();
	}
	
	leastFrequentlyUsedCache(capacity,vvec);
	return 0;
}

