#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vec[1000];

struct TreeNode {
	TreeNode *left, *right;
	int val;
};

TreeNode *createTreeNode(int val)
{
	TreeNode *node = new TreeNode;
	node->left = NULL; node->right = NULL; node->val = val;
	return node;
}

void preorder(TreeNode *root)
{
	if (root == NULL)
		return;

	cout << root->val << " ";
	preorder(root->left);
	preorder(root->right);
}

TreeNode* lca(TreeNode *root, int n1, int n2)
{
	if (root == NULL)
		return NULL;

	if (root->val == n1 || root->val == n2)  //
		return root;

	TreeNode *left_lca = lca(root->left, n1, n2);
	TreeNode *right_lca = lca(root->right, n1, n2);

	if (left_lca != NULL && right_lca != NULL)
		return root;
	else if (left_lca != NULL)
		return left_lca;
	else if (right_lca != NULL)
		return right_lca;
	else
		return NULL;
}

bool find(TreeNode *root, int k)
{
	if (root == NULL)
		return false;

	if (root->val == k || find(root->left, k) || find(root->right, k))
		return true;

	return false;
}

int main()
{
	TreeNode *root = createTreeNode(1);
	
	root->left = createTreeNode(2);
	root->right = createTreeNode(3);
	root->left->left = createTreeNode(4);
	root->left->right = createTreeNode(5);
	root->right->left = createTreeNode(6);
	root->right->right = createTreeNode(7);

	//preorder(root);

	int n1, n2;
	n1 = 6;
	n2 = 7;

	if (find(root, n1) && find(root, n2))
		cout << lca(root, n1, n2)->val;
	else
		cout << -1;
}

