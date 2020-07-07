/*
The basic concept is that you cant have two elements occurring more than n/2 times in an array. So what this algorithm does is 
try to cancel out each element with a differing element . This way, if a majority element exists, it will still persist till the end.

https://leetcode.com/problems/majority-element/submissions/
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int li;

//10, 2, 2, 4, 2, 3, 2, 2
int findMajorityElement(int a[],int n,int *chk)
{
	int i,res;
	
	//finding the candidate (probale index of majority element if it exists)
	int candidate,count=0;
	for(i=0;i<n;i++)
	{
		if(count==0)
		{
			candidate=a[i];
			count=1;
		}
		else
		{
			if(candidate==a[i])
				count++;
			else
				count--;
		}
	}

	//candidate
	
	//checking whether our candidate is majority element or not
	count=0;
	for(i=0;i<n;i++)
	{
		if(candidate==a[i])
			count++;
	}
	
	if(count>(n/2))
		res=candidate;
	
	*chk=0;
	return res;
}

int main()
{
	int n,i;
	cin>>n;
	int a[n];
	
	int chk=1;
	int res;
	res=findMajorityElement(a,n,&chk);
	if(chk)
		cout<<res;
	else
		cout<<-1;
			
	return 0;
}

