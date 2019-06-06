/*
	You get as an input two strings
 
W1 and W2 , W1 is regular expression , it is a string among the following chars : a-z,A-Z,0-9,*,?
* Means any finite number of chars.
? means only single char.
W2 is word and it is a string among the following chars : a-z,A-Z,0-9.
regular expression defines set words.
 
W1 = 1*2? This is the regular expression.
W2 3322a it does not belong to L(W1)
W2 123 Belongs to L(W1) because * get zero chars and 3 replace the ? and it starts with 1 and it has 2.
W2 12222223  belongs to L(W1)
W2 1assd2222y belongs to L(W1)
W2 122 to L(W1).
W2 12 does not belong to L(W1)
 
Write a function that takes W1 and W2 and returns true if W2 in L(W1) and false otherwise.
*/

#include<bits/stdc++.h>
using namespace std;

bool check(string str1,string str2,int i,int j)
{
	if(str1[i]=='?')
		return true;
	else if(str1[i]==str2[j])
		return true;
		
	return false;
}

bool find(string str1,string str2,int i,int j,int n,int m)
{
	//positive scenerio
	if(i==n && j==m)
		return true;
	
	//negative scenerios
	if(str1[i]=='*' && i<n-1 && j==m)  //abc* abcpqrxy
	{
		//cout<<"debug";
		return false;
	}
		
	if(i<n && str1[i]!='*')
	{
		if(check(str1,str2,i,j))
			return find(str1,str2,i+1,j+1,n,m);
	}
	
	if(i<n && str1[i]=='*')
		return find(str1,str2,i+1,j,n,m) || find(str1,str2,i,j+1,n,m);
	
	return false;
}

int main()
{
	string str1, str2;
	int T;
	cin>>T;
	while(T--)
	{
		int n,m;
		cin>>str1>>str2;
		n=str1.size(); m=str2.size();
		if(find(str1,str2,0,0,n,m))
			cout<<"String matches\n";
		else
			cout<<"Don't matches\n";
	}	
}

