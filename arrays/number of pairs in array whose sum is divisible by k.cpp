#include<bits/stdc++.h>
using namespace std;
typedef long long int li;

int nC2(int val)
{
	int res;
	if(val%2==0)
		return (val/2)*(val-1);
	
	return val*((val-1)/2);
}

int main()
{
	li n,i,j,key,x;
	cin>>n>>key;
	
	int cnt[key]={0};
	for (i=0;i<n;i++) {
		cin>>x;
		cnt[x%key]++;
	}
	
	int ans=nC2(cnt[0]);
	if(key%2==0) 
		ans+=nC2(cnt[key/2]);
		
	for(i=1;i<(key+1)/2;i++) 
	{
		j=key-i;
		ans+=cnt[i]*cnt[j];
	}
	
	cout<<ans<<endl;
	return 0;
}

/*
Input
6 4
2 2 1 7 5 3
Output
5

Input
6 4
7 2 5 3 4 1
Output
4
*/

