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

int checkIdentical(TreeNode *A,TreeNode *B)
{
	if(!A && !B)
        return 1;
    else if((!A && B) || (A && !B))
        return 0;
    
    if(A->val != B->val)
        return 0;
        
    return (checkIdentical(A->left,B->left) && checkIdentical(A->right,B->right));
}

int checkSymmetric(TreeNode *A,TreeNode *B)
{
	if(A==NULL && B==NULL)
        return 1;
    else if(A==NULL || B==NULL)
        return 0;
    
    if(A->val != B->val)
        return 0;
    
    return checkSymmetric(A->left,B->right) && checkSymmetric(A->right,B->left);
}

void invertTree(TreeNode *A)
{
	if(A==NULL)
		return ;
    
    invertTree(A->left);
    invertTree(A->right);

    TreeNode *temp=A->left;
    A->left=A->right;
    A->right=temp;
}

void solve_this()
{
    TreeNode *root,*root1;
	
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

	root1=createNode(1);
	
	if(checkIdentical(root,root1)); //whether tree with root and tree with root1 are same or not
	if(checkSymmetric(root,root));   //whether tree with root is symmetric or not
	invertTree(root); //to make the mirror image of given tree
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


