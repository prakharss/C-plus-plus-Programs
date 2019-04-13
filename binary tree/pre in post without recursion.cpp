#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left,*right;	
};

TreeNode* createNode(int val)
{
	TreeNode *temp=new TreeNode;
	temp->val=val;
	temp->left=NULL;
	temp->right=NULL;
    
    return temp;
}

void preorder(TreeNode *root)
{
	stack<TreeNode*> st;
	st.push(root);

	while(!st.empty())
	{
		TreeNode *temp=st.top();
		st.pop();
		cout<<temp->val<<" ";

		if(temp->right)
			st.push(temp->right);

		if(temp->left)
			st.push(temp->left);
	}
}

void inorder1(TreeNode *root)
{
	TreeNode *temp;
    stack<TreeNode*> st;
    
    temp=root;
    while(temp)
    {
        st.push(temp);
        temp=temp->left;
    }
    
    while(!st.empty())
    {   
        TreeNode *tp=st.top();
        st.pop();
        cout<<tp->val<<" ";
        
        temp=tp->right;
        while(temp)
        {
            st.push(temp);
            temp=temp->left;
        }
    } 
}

void inorder2(TreeNode *root)
{
	TreeNode *temp;
    stack<TreeNode*> st;
    
    temp=root;
    
    while(1)
    {   
        while(temp)
        {
            st.push(temp);
            temp=temp->left;
        }
        
        if(!st.empty())
        {
            TreeNode *tp=st.top();
            st.pop();
            temp=tp->right;
            cout<<tp->val<<" ";
        }
        else
            break;
    } 
}

void postorder(TreeNode *root)
{
	stack<TreeNode*> st;
	st.push(root);
	vector<int> vec;

	while(!st.empty())
	{
		TreeNode *temp=st.top();
		st.pop();
		vec.push_back(temp->val);

		if(temp->left)
			st.push(temp->left);

		if(temp->right)
			st.push(temp->right);
	}

	reverse(vec.begin(),vec.end());
	for(int i=0;i<vec.size();i++)
		cout<<vec[i]<<" ";
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
			   
	root=createNode(1);
	root->left=createNode(2);
	root->right=createNode(3);
	root->left->left=createNode(4);
	root->left->right=createNode(5);
	root->right->left=createNode(6);
	root->right->right=createNode(7);
	
	preorder(root);cout<<endl;
	inorder1(root);cout<<endl;
    inorder2(root);cout<<endl;
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


