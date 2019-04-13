#include <bits/stdc++.h>
using namespace std;
typedef long long int li;

int main()
{
	li i,n,key,capacity,val,rem;
    string str;
	cin>>n>>capacity;
	
    map<li,li> mp;
    queue<li> que;
    
    while(n--)
    {
        cin>>str>>key;
        
        if(str=="get")
        {
            if(mp.find(key)!=mp.end())
                cout<<mp[key]<<"\n";
            else
                cout<<-1<<"\n";   
        }
        else if(str=="set")
        {
            cin>>val;
            if(mp.find(key)==mp.end())
            {
                if(mp.size()<capacity)
                    mp[key]=val;
                else
                {
                    rem=que.front();
                    mp.erase(rem);
                
                    mp[key]=val;
                }
                
            } 
        }
        
        if(que.size()<capacity)
            que.push(key);
        else
        {
            que.pop();
            que.push(key);
        }
    }
    
	return 0;
}


