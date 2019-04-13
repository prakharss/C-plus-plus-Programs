/*
to learn stl
predict the output of following program
reference for stl for all imp and frequently used containers
any alternative statement is written using single line comment in the same line


INDEX   
container                                     line
1)vector:                                     36
2)map:                                        99
3)set:                                        164
4)pair:                                       228
5)queue:                                      278
6)stack:                                      314
7)priority queue(max and min heap):           353
8)deque:                                      393
*/ 
            
#include<bits/stdc++.h>
using namespace std;

void stl()
{
	int i,j,sz,n,t,x,y,chk=1;
	char ch;
	while(chk)
	{
		
	cout<<"choose your option\n";
	cout<<"1)vector 2)map 3)set 4)pair 5)queue 6)stack 7)priority_queue 8)deque\n";
	cin>>n;
	
	if(n==1)
	{
		//vector 
		
		/*
		- imp member functions:
		push_back(),pop_back(),size(),empty(),resize(),front(),back(),erase(),clear()
		- iterator exist
		- sort(vec.begin(),vec.end())
		- reverse(vec.begin(),vec.begin()+5) 
		*/
		
		cout<<"\nVECTOR\n\n";
		vector<int> v1;
		vector<int> v2(4,8);        //size of v2 is 4 with it's value asssigned to 8
		vector<vector<int> > v3;    //vector<int> vec[100] - both works in same way
		vector<int>::iterator vit;
		vector<vector<int> >::iterator vvit;
		vector<int>::reverse_iterator vrit;
		
		for(i=0;i<4;i++)
			v1.push_back(i);
			
		for(i=0;i<3;i++)
			v3.push_back(v1);
		
		cout<<"content of v1 vector using [] operator\n";	
		for(i=0;i<v1.size();i++)
			cout<<v1[i]<<" ";
		cout<<"\n\n";
		
		cout<<"content of v1 vector from start to last using iterator\n";
		for(vit=v1.begin();vit!=v1.end();vit++)
			cout<<*vit<<" ";
		cout<<"\n\n";
		
		cout<<"content of v1 vector from last to start using reverse iterator\n";
		for(vrit=v1.rbegin();vrit!=v1.rend();vrit++)
			cout<<*vrit<<" ";
		cout<<"\n\n";
		
		cout<<"content of v2 vector as it's size is 4 and all it's element are assigned to 8\n";
		for(i=0;i<v2.size();i++)
			cout<<v2[i]<<" ";
		cout<<"\n\n";
		
		cout<<"content of v3 vector of vector using [] operator\n";
		for(i=0;i<v3.size();i++)
		{
			for(j=0;j<v3[i].size();j++)
				cout<<v3[i][j]<<" ";
			cout<<"\n";
		}cout<<"\n";
		
		cout<<"content of v3 vector of vector using iterator\n";
		for(vvit=v3.begin();vvit!=v3.end();vvit++)
		{
			for(vit=(*vvit).begin();vit!=(*vvit).end();vit++)
				cout<<*vit<<" ";
			cout<<"\n";
		}cout<<"\n";
	}
	
	else if(n==2)
	{
		//map 
		
		/*
		- imp member functions:
		insert(),count(),erase(),find(),size(),empty(),clear()
		- count() searches the container for elements with a key equivalent to k and returns the number of matches.
		- Because all elements in a map container are unique, the count function can only return 1 (if the element is found) or zero (otherwise).
		- key-value concept
		- imp: find() and count() needs key value as argument and find() returns iterator
		- imp: erase() can take both iterator as well as key for argument
		- iterator exist
		*/
		
		cout<<"\nMAP\n\n";
		map<int,int> mp;  //map is the implementation of red black tree  //if not mentioned then map is considered as ordered map in which every operation is O(logN)
		map<int,int>::iterator mpit;
		map<int,int>::reverse_iterator mprit; 
		pair<int,int> pa;
		
		cout<<"Enter no. of elements in your map\n";
		cin>>n;
		cout<<"Enter your pairs to be inserted in map\n";
		for(i=0;i<n;i++)
		{
			cin>>x>>y;  
			pa.first=x;  pa.second=y;
			mp.insert(pa);  //mp[x]=y  //mp.insert(make_pair(x,y))	
		}cout<<"\n";
		
		cout<<"size of map\n"<<mp.size()<<"\n\n";
		
		cout<<"content of map using [] operator but set elements is only accessible using iterator and map elements can be accessed both by [] and iterator\n";
		for(i=-100000;i<100000;i++)
		{
			if(mp.find(i)!=mp.end())           //if this is true it means i exist in our map
				cout<<i<<" "<<mp[i]<<"\n";
		}cout<<"\n\n";
		
		cout<<"content of map using iterator\n";
		for(mpit=mp.begin();mpit!=mp.end();mpit++)
			cout<<(*mpit).first<<" "<<(*mpit).second<<"\n";  //cout<<mpit->first<<" "<<mpit->second<<"\n";
		cout<<"\n\n";
			
		cout<<"content of map using reverse iterator\n";
		for(mprit=mp.rbegin();mprit!=mp.rend();mprit++)
			cout<<(*mprit).first<<" "<<(*mprit).second<<"\n";  //cout<<mprit->first<<" "<<mprit->second<<"\n";
		cout<<"\n\n";
		
		cout<<"content of map while deleting all it's element one by one using erase\n";
		mpit=mp.begin();
		while(!mp.empty())
		{
			cout<<(*mpit).first<<" "<<(*mpit).second<<"\n";
			if(mp.find((*mpit).first)!=mp.end())        //mp.find(key_value)
			{
				map<int,int>::iterator temp=mpit;
				mpit++;
				mp.erase((*temp).first);             //mp.erase(temp) i.e mp.erase(any iterator)   //mp.erase(iterator1,iterator2)
			}
		}
		cout<<"\n\n";
		
		cout<<"size of map\n"<<mp.size()<<"\n\n";
	}
	
	else if(n==3)
	{
		//set                    
		
		/*
		- imp member functions:
		insert(),erase(),find(),size(),empty(),clear()
		- key concept 
		- imp: find() needs key value as argument and find() returns iterator
		- imp: erase() can take both iterator as well as key for argument
		- iterator exist
		*/
		
		cout<<"\nSET\n\n";         //implementation of red black tree
		set<int> st;
		set<int>::iterator stit;
		set<int>::reverse_iterator strit; 
		
		cout<<"Enter no. of elements in your set\n";
		cin>>n;
		cout<<"Enter your elements in set\n";
		for(i=0;i<n;i++)
		{
			cin>>x;
			st.insert(x);  	
		}cout<<"\n";
		
		cout<<"size of set\n"<<st.size()<<"\n\n";
		
		cout<<"content of set using find()\n";
		for(i=-100000;i<100000;i++)
		{
			if(st.find(i)!=st.end())           //if this is true it means i exist in our map
				cout<<i<<"\n";
		}cout<<"\n\n";
		
		cout<<"content of set using iterator\n";
		for(stit=st.begin();stit!=st.end();stit++)
			cout<<*stit<<"\n";  //cout<<stit->first<<" "<<stit->second<<"\n";
		cout<<"\n\n";
			
		cout<<"content of map using reverse iterator\n";
		for(strit=st.rbegin();strit!=st.rend();strit++)
			cout<<*strit<<"\n";  //cout<<strit->first<<" "<<strit->second<<"\n";
		cout<<"\n\n";
		
		cout<<"content of set while deleting all it's element one by one using erase\n";
		stit=st.begin();
		while(!st.empty())
		{
			cout<<*stit<<"\n";
			if(st.find(*stit)!=st.end())        //st.find(key_value)
			{
				set<int>::iterator temp=stit;
				stit++;
				st.erase(*temp);             //st.erase(temp) i.e st.erase(any iterator)  //st.erase(iterator1,iterator2)
			}
		}
		cout<<"\n\n";
		
		cout<<"size of set\n"<<st.size()<<"\n\n";
	}
	
	
	else if(n==4)
	{
		//pair
		cout<<"\nPAIR\n\n";
		pair<int,int> pa;
		cout<<"fill your pair by typing any two value seperated by space\n";
		cin>>x>>y;
		pa.first=x;  pa.second=y;    //pa=make_pair(x,y)
		cout<<"pair value\n";
		cout<<pa.first<<" "<<pa.second<<"\n\n";
		
		
		//array of pairs
		cout<<"how many pair you want in an array\n";
		cin>>n;
		pair<int,int> parr[n];
		cout<<"type your pairs to fill in an array\n";
		for(i=0;i<n;i++)
		{
			cin>>x>>y;
			parr[i]=make_pair(x,y);  //parr[i].first=x;  parr[i].second=y; 
		}cout<<"\n";
		
		sort(parr,parr+n);
		
		cout<<"content of array after sorting according to first value and then second value is considered i.e this sorting is not stable\n";
		for(i=0;i<n;i++)
			cout<<parr[i].first<<" "<<parr[i].second<<"\n";
		cout<<"\n\n";
		
		
		//vector of pairs
		cout<<"how many pairs you want in your vector\n";
		cin>>n;
		vector<pair<int,int> > vpa;
		cout<<"type your pairs to fill in a vector\n";
		for(i=0;i<n;i++)
		{
			cin>>x>>y;
			vpa.push_back(make_pair(x,y));   //pa.first=x; pa.second=y; vpa.push_back(pa) where pa is pair<int,int>
		}cout<<"\n";
		
		sort(vpa.begin(),vpa.end());
		
		cout<<"content of vector after sorting\n";
		for(i=0;i<vpa.size();i++)
			cout<<vpa[i].first<<" "<<vpa[i].second<<"\n";
		cout<<"\n\n";
	}
	
	else if(n==5)
	{
		//queue 
		
		/*
		- imp member functions:
		push(),pop(),front(),back(),size(),empty()
		- iterator don't exist
		*/
		
		cout<<"\nQUEUE\n\n";
		queue<int> que,temp_que;
		
		cout<<"Enter no. of elements u want in your queue\n";
		cin>>n;
		cout<<"\nEnter your elements\n";
		for(i=0;i<n;i++)
		{
			cin>>t;
			que.push(t);	
		}cout<<"\n";
			 
		cout<<"content of queue\n";
		while(!que.empty())
		{
			cout<<que.front()<<" ";
			temp_que.push(que.front());
			que.pop();
		}cout<<"\n\n";
		
		cout<<"last element of our queue\n";
		cout<<temp_que.back()<<" ";
		cout<<"\n\n";
	}
		
	
	else if(n==6)
	{
		//stack 
		
		/*
		- imp member functions:
		push(),pop(),top(),size(),empty()
		- iterator don't exist
		*/
		
		cout<<"\nSTACK\n\n";
		stack<int> stk,temp_stk;
		
		cout<<"Enter no. of elements u want in your stack\n";
		cin>>n;
		cout<<"\nEnter your elements\n";
		for(i=0;i<n;i++)
		{
			cin>>t;
			stk.push(t);	
		}cout<<"\n";
		 
		cout<<"content of stack from last to start using given stack\n";
		while(!stk.empty())
		{
			cout<<stk.top()<<" ";
			temp_stk.push(stk.top());
			stk.pop();
		}cout<<"\n\n";
		
		cout<<"content of stack from start to last using temporary stack\n";
		sz=temp_stk.size();
		for(i=0;i<sz;i++)
		{
			cout<<temp_stk.top()<<" ";
			temp_stk.pop();
		}cout<<"\n\n"; 
	}
	
	else if(n==7)
	{
		//priority_queue (we can implement both max heap and min heap using this container)
		
		/*
		- imp member functions:
		push(),pop(),top(),size(),empty()
		- iterator don't exist
		*/
		
		cout<<"\nPRIORITY QUEUE\n\n";
		priority_queue<int> pq_mx;   //max_heap by default
		priority_queue<int, vector<int> , greater<int> > pq_mn;   //this is the syntax for min heap
		
		cout<<"Enter no. of elements u want in your priority queue\n";
		cin>>n;
		cout<<"\nEnter your elements\n";
		for(i=0;i<n;i++)
		{
			cin>>t;
			pq_mx.push(t); pq_mn.push(t);	
		}cout<<"\n";
		
		cout<<"size of heap\n";  cout<<pq_mx.size()<<"\n\n";
		
		cout<<"content of max heap\n";
		while(!pq_mx.empty())
		{
			cout<<pq_mx.top()<<" ";
			pq_mx.pop();
		}cout<<"\n\n";
		
		cout<<"content of min heap\n";
		while(!pq_mn.empty())
		{
			cout<<pq_mn.top()<<" ";
			pq_mn.pop();
		}cout<<"\n\n";
	}
	
	else if(n==8)
	{
		//deque
		
		/*
		- imp member functions:
		push_front(),push_back(),pop_front(),pop_back(),front(),back(),size(),empty()
		- iterator exist
		*/
		
		cout<<"\nDEQUE\n\n";
		deque<int> dq;
		deque<int>::iterator dqit;
		deque<int>::reverse_iterator dqrit;
		
		for(i=0;i<4;i++)
			dq.push_back(i);
		
		cout<<"content of deque using [] operator\n";	
		for(i=0;i<dq.size();i++)
			cout<<dq[i]<<" ";
		cout<<"\n\n";
			
		cout<<"content of deque by taking out all elements from deque in forward direction\n";	
		while(!dq.empty())
		{
			cout<<dq.front()<<" ";
			dq.pop_front();
		}cout<<"\n\n";
		
		for(i=0;i<4;i++)
			dq.push_back(i);
			
		cout<<"content of deque by taking out all elements from deque in backward direction\n";	
		while(!dq.empty())
		{
			cout<<dq.back()<<" ";
			dq.pop_back();
		}cout<<"\n\n";
		
		for(i=0;i<4;i++)
			dq.push_back(i);
			
		cout<<"content of deque using iterator\n";
		for(dqit=dq.begin();dqit!=dq.end();dqit++)
			cout<<*dqit<<" ";
		cout<<"\n\n";
			
		cout<<"content of deque using reverse iterator\n";
		for(dqrit=dq.rbegin();dqrit!=dq.rend();dqrit++)
			cout<<*dqrit<<" ";
		cout<<"\n\n";	
	}
	cout<<"press 'n' for exit and 'y' for continue\n";
	cin>>ch; cout<<"\n";
	if(ch=='y')
		chk=1;
	else
		chk=0;
	}
}

int main()
{
	stl();
	return 0;
}


