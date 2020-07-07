/*
We can optimise this using hashmap
*/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left,*right;	
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void postorder(TreeNode *root)
{
	if(root==NULL)
	return ;
	
	postorder(root->left);
	postorder(root->right);
    cout<<root->val<<" ";
}

int cnt;
TreeNode *makeBinaryTreeUsingInAndPre(vector<int> &inorder, vector<int> &preorder, int l, int r)
{
    if(l>r)
        return NULL;
    
    int mid; 
    
    //no need to do this
    //take the map<node, index> mp
    for(int i=l;i<=r;i++)
    {
        if(inorder[i]==preorder[cnt])
        {
            mid=i;
            cnt++;
            break;
        }
    }
    
    TreeNode *root=new TreeNode(inorder[mid]);
    root->left=makeBinaryTreeUsingInAndPre(inorder,preorder,l,mid-1);
    root->right=makeBinaryTreeUsingInAndPre(inorder,preorder,mid+1,r);
    
    return root;
}

void solve_this()
{
    int n,t,i;
    cin>>n;
    
    vector<int> inorder;
    for(i=0;i<n;i++)
    {
        cin>>t;
        inorder.push_back(t);  //Left Root Right
    }
    
    vector<int> preorder;
    for(i=0;i<n;i++)
    {
        cin>>t;
        preorder.push_back(t);  //Root Left Right
    }
    
    cnt=0;
    TreeNode *root=makeBinaryTreeUsingInAndPre(inorder,preorder,0,n-1);
    postorder(root);
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


