#include<bits/stdc++.h>
using namespace std;

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

void inorder(TreeNode *root)
{
	if(root==NULL)
	return ;
	
	inorder(root->left);
	cout<<root->val<<" ";
	inorder(root->right);
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
	
	inorder(root);	
	return 0;
}


