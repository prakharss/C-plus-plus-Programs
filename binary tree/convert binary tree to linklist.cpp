//https://www.interviewbit.com/problems/flatten-binary-tree-to-linked-list/
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

void inorder(TreeNode *A)
{
	if(A==NULL)
		return ;

	inorder(A->left);
	cout<<A->val<<" ";
	inorder(A->right);
}

void convertBinaryTreeToLinkList(TreeNode *A)
{
	if(A==NULL)
	return ;
	
	convertBinaryTreeToLinkList(A->left);
	convertBinaryTreeToLinkList(A->right);

	TreeNode *temp=A->left;
	if(temp)
	{
		while(temp->right)
		temp=temp->right;

		temp->right=A->right;
		A->right=A->left;
		A->left=NULL;
	}
    
    return A;
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
	
	inorder(root);cout<<"\n";
	convertBinaryTreeToLinkList(root);
    
    /*
    converting above binary tree to following type of linklist 
            1
             \
              2
               \ 
                4
                 \
                  5
                   \
                    3
                     \ 
                      6
                       \
                        7
    */
    
	inorder(root);
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


