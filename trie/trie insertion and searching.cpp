//search - O(str.size()) and insert - O(26*str.size())
#include<bits/stdc++.h>
using namespace std;

struct TrieNode{
	bool end;
	TrieNode *nextchar[26];
};

TrieNode* createNode()
{
	TrieNode *temp;
	temp=new TrieNode;
	temp->end=false;
	
	for(int i=0;i<26;i++)
		temp->nextchar[i]=NULL;
	
	return temp;
}

void insert(TrieNode *root,string str)
{
	for(int i=0;i<str.size();i++)
	{
		if(root->nextchar[str[i]-'a']==NULL)
		{
			TrieNode *temp;
			temp=createNode();
			root->nextchar[str[i]-'a']=temp;
			root=temp;
		}
		else
		root=root->nextchar[str[i]-'a'];
	}

	root->end=true;
}

bool search(TrieNode *root,string str)
{
	for(int i=0;i<str.size();i++)
	{
		if(root->nextchar[str[i]-'a']==NULL)
		return false;
		else
		root=root->nextchar[str[i]-'a'];
	}

	return root->end;
}


void TrieDataStructure()
{
	//we are searching some strings from set of all strings - trie is best for this one
	int i,n,q;
	string str;
	TrieNode *root;
	root=createNode();  //null creation 
	
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>str;
		insert(root,str);    
	}
	
	cin>>str;
	if(search(root,str))
		cout<<str<<" is present\n";
	else
		cout<<str<<" is not present\n";
}

int main()
{
ios_base::sync_with_stdio(false); cin.tie(0);
TrieDataStructure();
return 0;
}


