#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left,*right;	
};

TreeNode* createNode(int val)
{
	TreeNode *temp=new TreeNode;
	temp->val=val;
	temp->left=NULL;
	temp->right=NULL;
    
    return temp;
}

map<int, vector<int> > mp;
map<int, vector<int> > :: iterator mpit;

void verticalorder(TreeNode *A)
{
    queue<pair<TreeNode*,int> > que;

    if(A)
    que.push(make_pair(A,0));

    while(!que.empty())
    {
    	pair<TreeNode*,int> temp=que.front();
        que.pop();
    	TreeNode *currNode=temp.first;
    	int currVal=temp.second;

    	mp[currVal].push_back(currNode->val);

    	if(currNode->left)
    	que.push(make_pair(currNode->left,currVal-1));
    	
    	if(currNode->right)
    	que.push(make_pair(currNode->right,currVal+1));
    }
}

void solve_this()
{
    TreeNode *root;
	
	/*
	we are making complete binary tree having 7 nodes value from 1 to 7
				1
			   / \
			  2   3
			 /\   /\ 
			4  5  6 7 
	*/
			   
	root=createNode(1);
	root->left=createNode(2);
	root->right=createNode(3);
	root->left->left=createNode(4);
	root->left->right=createNode(5);
	root->right->left=createNode(6);
	root->right->right=createNode(7);
	
    verticalorder(root);
    
    for(mpit=mp.begin();mpit!=mp.end();mpit++)
    {
        vector<int> temp=mpit->second;
        for(int i=0;i<temp.size();i++)
            cout<<temp[i]<<" ";
        
        cout<<"\n";
    }
}

int main()
{
ios_base::sync_with_stdio(false); cin.tie(0);
//freopen("i.txt","r",stdin);
//freopen("o.txt","w",stdout);
//li T;  cin>>T;  W(T--)
solve_this();
return 0;
}


