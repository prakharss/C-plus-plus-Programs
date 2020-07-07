/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*Given a binary tree. Check whether the given tree is a Sum-binary tree or not. 
SumTree is a Binary Tree where the value of a node is equal to sum of the nodes 
present in its left subtree and right subtree. An empty tree is SumTree and 
sum of an empty tree can be considered as 0. A leaf node is also considered as SumTree. 
Return 1 if it sum-binary tree else return 0*/

//approach 1
int util(TreeNode *A,int *sum) {
    if(A==NULL) {
        *sum=0;
        return 1;
    }
    
    int leftSum=0; int rightSum=0;
    int l=util(A->left,&leftSum);
    int r=util(A->right,&rightSum);
    
    *sum=leftSum+A->val+rightSum;
    
    if(A->left==NULL && A->right==NULL)
        return 1;
    
    if(leftSum+rightSum!=A->val)
        return 0;
        
    return l && r;
}
int Solution::solve(TreeNode* A) {
    int sum=0;
    return util(A,&sum);
}


//Same solution but taking global variable to mark the answer
//Approach 2
int util(TreeNode *A,int &chk) {
    if(A==NULL || !chk) {
        return 0;
    }
    
    int left=util(A->left,chk);
    int right=util(A->right,chk);
    
    if(!(A->left==NULL && A->right==NULL) && left+right!=(A->val))
        chk=0;
    
    return left+right+A->val;
}
int Solution::solve(TreeNode* A) {
    int chk=1;
    util(A,chk);
    return chk;
}

