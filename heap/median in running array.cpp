#include<bits/stdc++.h>
using namespace std;
typedef long long int li;

priority_queue<int> pqmx;
priority_queue<int, vector<int>, greater<int> > pqmn;

int util(int key,int median)
{
	int res,temp;
	int mxsz=pqmx.size(),mnsz=pqmn.size();
	if(mxsz==mnsz)
	{
		if(key<median)
		{
			pqmx.push(key);
			res=pqmx.top();
		}
		else
		{
			pqmn.push(key);
			res=pqmn.top();
		}
	}
	else if(mxsz-mnsz==1)
	{
		if(key<median)
		{
			temp=pqmx.top();
			pqmx.pop();
			pqmn.push(temp);
			pqmx.push(key);
		}
		else
		{
			pqmn.push(key);
		}
		
		res=(pqmn.top()+pqmx.top())/2;
	}
	else if(mxsz-mnsz==-1)
	{
		if(key<median)
		{
			pqmx.push(key);
		}
		else
		{
			temp=pqmn.top();
			pqmn.pop();
			pqmx.push(temp);
			pqmn.push(key);
		}
		
		res=(pqmn.top()+pqmx.top())/2;
	}
	
	return res;
}

void printMedian(int a[],int n)
{
	int i;
	int median=0;
	for(i=0;i<n;i++)
	{
		median=util(a[i],median);
		cout<<median<<" ";
	}
}

int main()
{
	int n,i;
	cin>>n;
	int a[n];
	
	for(i=0;i<n;i++)
		cin>>a[i];
	
	printMedian(a,n);
	return 0;
}

