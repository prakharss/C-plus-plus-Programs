/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int Solution::hasPathSum(TreeNode* A, int B) {
    if(A==NULL) {
        return 0;
    }
    
    if(A->left==NULL && A->right==NULL && B==(A->val)) {
        return 1;    //return (B==(A->val)); //i.e no need to go to left or right side of a leaf node
    }
    
    return hasPathSum(A->left,B-(A->val)) || hasPathSum(A->right,B-(A->val));
}
