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

TreeNode *findTargetNode(TreeNode *A,int val)
{
    while(A->val!=val)
    {
        if(A->val>val)
    	A=A->left;
        else if(A->val<val)
    	A=A->right;    
    }

    return A;
}

TreeNode *minNodeInRight(TreeNode *A)
{
	while(A->left)
	A=A->left;
	
	return A;
}

TreeNode *findInorderSuccessor(TreeNode *A,TreeNode *target)
{
    if(target->right)
    return minNodeInRight(target->right);
    
    TreeNode *succ=NULL;
	while(A->val!=target->val)
	{
		if(A->val>target->val)
		{
			succ=A;
			A=A->left;
		}
		else if(A->val<target->val)
			A=A->right;
	}

	return succ;
}

int main()
{
	int i,n,t,val;
	cin>>n;
	
	cin>>t;
	TreeNode *root=makeNode(t);
	
    TreeNode *target;
	for(i=0;i<n-1;i++)
	{
		cin>>t;
		bstInsertRec(root,t);
	}
	
    //target value
    cin>>val;
    
    //find target TreeNode for val
    target=findTargetNode(root,val);
    
    //writing algo to find successor of node having value val
    TreeNode *result=findInorderSuccessor(root,target);
    
    if(result)
	cout<<result->val;
    else
    cout<<"no inorder successor";
    
	return 0;
}


