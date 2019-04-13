#include<bits/stdc++.h>
using namespace std;

struct TrieNode{
	bool end;
	TrieNode *nextchar[26];
};

TrieNode* createNode()
{
	TrieNode *n;
	n=new TrieNode;
	n->end=false;
	
	for(int i=0;i<26;i++)
		n->nextchar[i]=NULL;
	
	return n;
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

bool cmp(pair<int,int> pa1, pair<int,int> pa2)
{
    return pa1.second>pa2.second;
}

void TrieDataStructure()
{
	//we are searching some strings from set of all strings - trie is best for this one
	int i,j,n,q,review,cnt;
	string str,s;
	TrieNode *root;
	root=createNode(); //null creation 
	
	cin>>s; n=s.size(); s=s+"_";
    str=""; i=0;
	while(i<n)
    {
        str=str+s[i];
		if(s[i+1]=='_')
        {
            //cout<<str<<" ";
            insert(root,str);
            str=""; i++;
        }
        i++;
    }
    
    vector<pair<int,int> > vecpa;
        
    cin>>review;
    for(j=0;j<review;j++)
    {
        cin>>s; n=s.size(); s=s+"_";
        str=""; i=0; cnt=0;
        
        while(i<n)
        {
            str=str+s[i];
            if(s[i+1]=='_')
            {
                //cout<<str<<" ";
                if(search(root,str))
                    cnt++;
                
                str=""; i++;
            }
            i++;
        }
        
     // cout<<cnt<<" "<<j<<"\n";
        vecpa.push_back(make_pair(j,cnt));
    }
    
    sort(vecpa.begin(),vecpa.end(),cmp);
    
    for(i=0;i<vecpa.size();i++)
        cout<<vecpa[i].first<<" ";  
}

int main()
{
ios_base::sync_with_stdio(false); cin.tie(0);
TrieDataStructure();
return 0;
}


