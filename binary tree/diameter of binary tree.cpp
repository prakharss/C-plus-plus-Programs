/*
https://www.geeksforgeeks.org/diameter-of-a-binary-tree-in-on-a-new-method/
diameter of a tree is nothing but maximum value of (left_height + right_height + 1) for each node
O(n) and O(n^2)

Discuss one more method to manipulate height in same call
*/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left,*right;	
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

int heightOfBinaryTree1(TreeNode *root, int &ans)
{
	if(!root)
		return 0;

	int l,r;
	l=heightOfBinaryTree1(root->left,ans);
	r=heightOfBinaryTree1(root->right,ans);

	ans=max(ans,l+r+1);
	return max(l,r)+1;
}

int diameterOfBinaryTreeLinear(TreeNode *root)         //O(n)
{						//diameter of a tree is nothing but maximum value of (left_height + right_height + 1) for each node
	if(!root)
		return 0;

	int ans=INT_MIN;
	heightOfBinaryTree1(root,ans);
	
	return ans;
}

int heightOfBinaryTree2(TreeNode *root)
{
	if(!root)
		return 0;

	return max(heightOfBinaryTree2(root->left),heightOfBinaryTree2(root->right))+1;
}

int diameterOfBinaryTreeQuadratic(TreeNode *root)         //O(n^2)
{
	if(!root)
		return 0;

	int lh,rh;
	lh=heightOfBinaryTree2(root->left);
	rh=heightOfBinaryTree2(root->right);
    
    int ld,rd;
	ld=diameterOfBinaryTreeQuadratic(root->left);
	rd=diameterOfBinaryTreeQuadratic(root->right);
    
	return max(lh+rh+1, max(ld,rd));
}

void solve_this()
{
    TreeNode *root;
	
	/*
				1
			   / \
			  2   3
			 / \   
			4   5
		   /     \
          6       7
         /         \
        8           9
	*/
			   
	root=new TreeNode(1);
	root->left=new TreeNode(2);
	root->right=new TreeNode(3);
	root->left->left=new TreeNode(4);
	root->left->right=new TreeNode(5);
	root->left->left->left=new TreeNode(6);
	root->left->right->right=new TreeNode(7);
    root->left->left->left->left=new TreeNode(8);
    root->left->right->right->right=new TreeNode(9);
	
	cout<<diameterOfBinaryTreeLinear(root); 
    cout<<"\n";
	cout<<diameterOfBinaryTreeQuadratic(root);
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


