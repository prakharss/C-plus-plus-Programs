#include<bits/stdc++.h>
using namespace std;
typedef long long int li;

bool checkType(string str)
{
	int i=0;
	while(str[i]!=32)
	{
		i++;
	}
	
	if(str[i+1]>=48 && str[i+1]<=57)
		return 1;
		
	return 0;
}

string newLast(string s)
{
	int i=0;
	while(s[i]!=32)
		i++;
		
	string res;
	for(int j=i+1;j<s.size();j++)
		res=res+s[j];
		
	return res;
}

string newFirst(string s)
{
	int i=0;
	string res;
	while(s[i]!=32)
	{
		res=res+s[i];
		i++;
	}
	
	return res;
}

bool comp(string s1, string s2) 
{ 
    string t1,t2,f1,f2;
	t1=newLast(s1);
	t2=newLast(s2);
	
	f1=newFirst(s1);
	f2=newFirst(s2);
	
	if(t1==t2)
	{
		return f1<f2;	
	}
	
	return t1<t2;	
} 

vector<string> util(int numberOfBoxes, vector<string> boxList)
{
	int i,n=boxList.size();
	vector<string> newB;
	vector<string> oldB;
	for(i=0;i<n;i++)
	{
		if(checkType(boxList[i]))
			newB.push_back(boxList[i]);
		else
			oldB.push_back(boxList[i]);
	}
	
	int osz=oldB.size();  int nsz=newB.size();
	sort(oldB.begin(),oldB.end(),comp);
	
	vector<string> res;
	for(i=0;i<osz;i++)
		res.push_back(oldB[i]);
		
	for(i=0;i<nsz;i++)
		res.push_back(newB[i]);
		
	return res;
}

int main()
{
	li n,i;
	cin>>n;
	
	string str;
	vector<string> vec;
	
	getline(cin,str);
	str.clear();
	for(i=0;i<n;i++)
	{
		getline(cin,str);
		vec.push_back(str);	
		str.clear();
	}
	
	vector<string> res;
	res=util(n, vec);
	
	for(i=0;i<n;i++)
	{
		cout<<res[i]<<"\n";
	}
	
	/*cout<<"hi\n";
	
	cout<<newFirst("asfadf dfd ase dfdf");
	cout<<newLast("dfd dssdf xcvrtf ggxvb");*/
	
	return 0;
}
