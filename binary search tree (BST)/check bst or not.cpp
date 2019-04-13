#include<bits/stdc++.h>
using namespace std;

int previous=INT_MIN,curr,chk=1;

struct TreeNode{
	int val;
	TreeNode *left,*right;
};

TreeNode* makeNode(int t)
{
	TreeNode *temp=new TreeNode;
	temp->val=t;
	temp->left=temp->right=NULL;
	return temp;
}

TreeNode* bstInsertRec(TreeNode *root,int t)
{
	if(root==NULL)
	{
		TreeNode *temp=makeNode(t);
		return temp;
	}
	
	if(t>root->val)
	root->right=bstInsertRec(root->right,t);	
	else if(t<=root->val)
	root->left=bstInsertRec(root->left,t);
	
	return root;
}

void checkValidBst(TreeNode *root)
{
	if(root==NULL || chk==0)
	return ;
	
	checkValidBst(root->left);
	curr=root->val;
    
    if(curr<=previous)
        chk=0;
    previous=curr;
    
	checkValidBst(root->right);
}

int main()
{
	int i,n,t;
	cin>>n;
	
	cin>>t;
	TreeNode *root=makeNode(t);
	
	for(i=0;i<n-1;i++)
	{
		cin>>t;
		bstInsertRec(root,t);
	}
	
	previous=INT_MIN; chk=1;
	checkValidBst(root);	
    
    if(chk)
        cout<<"yes";
    else
        cout<<"no";
        
	return 0;
}


