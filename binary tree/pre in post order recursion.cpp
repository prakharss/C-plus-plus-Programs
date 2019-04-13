#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left,*right;	
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

void preorder(TreeNode *root)
{
	if(root==NULL)
	return ;
	
	cout<<root->val<<" ";
	preorder(root->left);
	preorder(root->right);
}

void inorder(TreeNode *root)
{
	if(root==NULL)
	return ;
	
	inorder(root->left);
	cout<<root->val<<" ";
	inorder(root->right);
}

void postorder(TreeNode *root)
{
	if(root==NULL)
	return ;
	
	postorder(root->left);
	postorder(root->right);
	cout<<root->val<<" ";
}

int main()
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
			   
	root=new TreeNode(1);
	root->left=new TreeNode(2);
	root->right=new TreeNode(3);
	root->left->left=new TreeNode(4);
	root->left->right=new TreeNode(5);
	root->right->left=new TreeNode(6);
	root->right->right=new TreeNode(7);
	
	preorder(root);cout<<endl;
	inorder(root);cout<<endl;
	postorder(root);
	
	return 0;
}


