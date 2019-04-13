//HERE WE ARE ASSUMING THAT val1 and val2 ARE ALREADY PRESENT IN GIVEN BST
#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left,*right;	
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

TreeNode* lcaOfBstUsingRecursion(TreeNode *root, int val1, int val2)  //IT TAKE EXTRA SPACE DUE TO RECURSION
{
    if(!root)
        return NULL;
    
    if(root->val>val1 && root->val>val2)
        return lcaOfBstUsingRecursion(root->left,val1,val2);
    
    if(root->val<val1 && root->val<val2)                                 //else if(root->val<val1 && root->val<val2)
        return lcaOfBstUsingRecursion(root->right,val1,val2);            //return lcaOfBstUsingRecursion(root->right,val1,val2);
    
    return root;                                                         //else return root;
}

TreeNode* lcaOfBstWithoutUsingRecursion(TreeNode *root, int val1, int val2)
{
    while(root)
    {
        if(root->val>val1 && root->val>val2)
            root=root->left;
        else if(root->val<val1 && root->val<val2)
            root=root->right;
        else
            break;
    }
    
    return root;
}

void solve_this()
{
    TreeNode *root;
	
	/*
	we are making complete binary tree having 7 nodes value from 1 to 7
				5
			   / \
			  3   7
			 /\   /\ 
			1  4  6 9 
	*/
			   
	root=new TreeNode(5);
	root->left=new TreeNode(3);
	root->right=new TreeNode(7);
	root->left->left=new TreeNode(1);
	root->left->right=new TreeNode(4);
	root->right->left=new TreeNode(6);
	root->right->right=new TreeNode(9);
	
    int val1,val2;
    cin>>val1>>val2;     //HERE WE ARE ASSUMING THAT val1 and val2 ARE ALREADY PRESENT IN GIVEN BST
	cout<<lcaOfBstUsingRecursion(root,val1,val2)->val<<"\n";
    cout<<lcaOfBstWithoutUsingRecursion(root,val1,val2)->val;    
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


