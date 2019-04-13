/*
O(n)
*/
#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left,*right;	
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

int numberOfNodesInBinaryTree(TreeNode *root)
{
	if(!root)
		return 0;

	return numberOfNodesInBinaryTree(root->left)+numberOfNodesInBinaryTree(root->right)+1;
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
			   
	root=new TreeNode(1);
	root->left=new TreeNode(2);
	root->right=new TreeNode(3);
	root->left->left=new TreeNode(4);
	root->left->right=new TreeNode(5);
	root->right->left=new TreeNode(6);
	root->right->right=new TreeNode(7);
	
	cout<<numberOfNodesInBinaryTree(root);
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


