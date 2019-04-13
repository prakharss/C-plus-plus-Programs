#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left,*right;	
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

stack<TreeNode *> st;
bool hasNext()
{
    return !st.empty();    
}

int next()
{
    TreeNode *tp=st.top();
    int val=tp->val;
    st.pop();
    
    TreeNode *temp=tp->right;
    while(temp)
    {
        st.push(temp);
        temp=temp->left;
    }
    
    return val;
}

void inorderUsingNextOfBst(TreeNode *root)
{
    TreeNode *temp=root;   
    while(temp)
    {
        st.push(temp);
        temp=temp->left;
    }
    
    while(hasNext())
    {
        int n=next();
        cout<<n<<" ";
    }
}

void solve_this()
{
    TreeNode *root;
	
	/*
	we are making complete binary tree having 7 nodes value from 1 to 7
				1
			   / \
			  2   3
			 /\   /\ 
			4  5  6 7 
	*/
			   
	root=new TreeNode(1);
	root->left=new TreeNode(2);
	root->right=new TreeNode(3);
	root->left->left=new TreeNode(4);
	root->left->right=new TreeNode(5);
	root->right->left=new TreeNode(6);
	root->right->right=new TreeNode(7);
	
	inorderUsingNextOfBst(root);
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


