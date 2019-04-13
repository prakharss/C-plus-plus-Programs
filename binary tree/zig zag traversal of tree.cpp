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

void zigZagTraversal(TreeNode *A)
{
	stack<TreeNode*> st1,st2;
	
	st1.push(A);
	while(!st1.empty() || !st2.empty())
	{
		if(!st1.empty())
		{
			while(!st1.empty())
			{
				TreeNode *temp=st1.top();
                cout<<temp->val<<" ";
                st1.pop();
				if(temp->left)
					st2.push(temp->left);

				if(temp->right)
					st2.push(temp->right);
			}
		}
		else if(!st2.empty())
		{
			while(!st2.empty())
			{
				TreeNode *temp=st2.top();
                cout<<temp->val<<" ";
                st2.pop();
				if(temp->right)
					st1.push(temp->right);

				if(temp->left)
					st1.push(temp->left);
			}
		}
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
	
	zigZagTraversal(root);
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


