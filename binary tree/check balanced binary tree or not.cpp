#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left,*right;	
};

int chk;

TreeNode* createNode(int val)
{
	TreeNode *temp=new TreeNode;
	temp->val=val;
	temp->left=NULL;
	temp->right=NULL;
    
    return temp;
}

int checkBalanceBinaryTree(TreeNode* A)
{
    if(A==NULL || chk==0)
        return 0;
    
    int u=checkBalanceBinaryTree(A->left);
    int v=checkBalanceBinaryTree(A->right);
    
    if(abs(u-v)>1)
        chk=0;
    
    return max(u,v)+1;
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
	
    chk=1;
	checkBalanceBinaryTree(root);
	if(chk)
	cout<<"yes";
	else
	cout<<"no";
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


