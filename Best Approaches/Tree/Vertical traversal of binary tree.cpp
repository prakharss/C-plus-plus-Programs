/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
//1st approach
void util(TreeNode *A,int &minDist,int &maxDist,unordered_map<int, vector<int> > &mp)
{
    queue<pair<TreeNode*,int> > que;
    if(A)
        que.push(make_pair(A,0));
    
    int dist;
    while(!que.empty()) {
    	pair<TreeNode*,int> temp=que.front();
        que.pop();
    	TreeNode *currNode=temp.first;
    	dist=temp.second;
        
        minDist=min(minDist,dist);
        maxDist=max(maxDist,dist);
    	mp[dist].push_back(currNode->val);

    	if(currNode->left)
    	    que.push(make_pair(currNode->left,dist-1));

    	if(currNode->right)
    	    que.push(make_pair(currNode->right,dist+1));
    }
}
vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    vector<vector<int> > res;
    if(!A)
        return res;
    
    unordered_map<int, vector<int> > mp;
    int minDist=INT_MAX,maxDist=INT_MIN;
    util(A,minDist,maxDist,mp);
    
    for(int i=minDist;i<=maxDist;i++)
        res.push_back(mp[i]);
        
    return res;
}

//2nd approach 
/*
dist,(min_priority_queue(height,list of node))
We can use unordered_map<int, priority_queue<pair<int,vector<int> >, vector<pair<int,vector<int>> > , greater<pair<int,vector<int> > > > mp;
*/