/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//similarly we can find bottom view
unordered_map<int,pair<int,int> > mp; 
int distMax,distMin;
void topView(TreeNode* A,int dist,int height) {
    if(A==NULL)
        return;
    
    if(mp.find(dist)==mp.end() || height<mp[dist].first) {
        mp[dist]=make_pair(height,A->val);
    }
   
    distMax=max(distMax,dist);
    distMin=min(distMin,dist);
    
    topView(A->left,dist-1,height+1);
    topView(A->right,dist+1,height+1);
    
    return;
}
vector<int> Solution::solve(TreeNode* A) {
    mp.clear();
    distMin=INT_MAX; distMax=INT_MIN; 
    topView(A,0,0);
    
    vector<int> res;
    for(int i=distMin;i<=distMax;i++) {
        res.push_back(mp[i].second);
    }
    
    return res;
}
