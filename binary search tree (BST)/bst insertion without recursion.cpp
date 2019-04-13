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

void bstInsert(TreeNode *root,int t)
{
	TreeNode *temp=makeNode(t),*prev;
	
	while(root!=NULL)
	{
		prev=root;
		if(t>root->val)
		root=root->right;
		else if(t<=root->val)
		root=root->left;
	}
	
	if(t>prev->val)
	prev->right=temp;
	else if(t<=prev->val)
	prev->left=temp;		
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
		bstInsert(root,t);
	}
	
	inorder(root);	

	return 0;
}



