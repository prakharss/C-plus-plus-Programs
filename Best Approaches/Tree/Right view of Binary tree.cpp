
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//Similarly we can find left view of binary tree
vector<int> res;
void rightView(TreeNode* A,int &L, int l) {
    if(A==NULL)
        return ;
    
    if(l>L) {
        res.push_back(A->val);
        L=l;
    }
    
    rightView(A->right,L,l+1);
    rightView(A->left,L,l+1);
    
    return ;
}

vector<int> Solution::solve(TreeNode* A) {
    res.clear();
    int L=-1;
    rightView(A,L,0);

    return res;
}
