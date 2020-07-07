/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//good question
vector<int> Solution::inorderTraversal(TreeNode* A) {
    stack<TreeNode*> st;
    
    vector<int> res;
    TreeNode* explore=A;
    while(!st.empty() || explore!=NULL) {
        while(explore!=NULL) {
            st.push(explore);
            explore=explore->left;
        }
        
        TreeNode *top=st.top();
        st.pop();
        res.push_back(top->val);
        
        explore=top->right;
    }
    
    /*
    while(!st.empty() || explore!=NULL) {
        if(explore!=NULL) {
            st.push(explore);
            explore=explore->left;
        }
        else {
            TreeNode *top=st.top();
            st.pop();
            res.push_back(top->val);
            
            explore=top->right;
        }
    }
    */
    
    return res;
}
