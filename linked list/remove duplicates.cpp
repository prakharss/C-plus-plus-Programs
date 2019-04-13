#include<bits/stdc++.h>
using namespace std;
typedef long long int li;
#define cc continue
#define bb break
#define rr return
#define W while
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define fir first
#define sec second

struct node
{
	int val;
	node *next;
};

node* createNode(int val)
{
	node *root=new node;
	root->val=val;
	root->next=NULL;
	
	return root;
}

void removeNode(node *prev,node *remove,node *head)
{
    prev->next=remove->next;
    delete(remove);
}

void removeDuplicates(node *head)
{	
	node *curr;
    curr=head;
    
    while(curr->next)
    {
        if(curr->val == curr->next->val)
            removeNode(curr,curr->next,head);    //delete curr->next
        else
            curr=curr->next;
    }
}

void solve_this()
{
	li n,i,t,val;
	node *head,*curr;
	cin>>n;
	
	cin>>t;
	head=createNode(t);
	curr=head;
	
	for(i=0;i<n-1;i++)
	{
		cin>>t;
		node *tmp=createNode(t);
		curr->next=tmp;
		
		curr=tmp;
	}
	
	removeDuplicates(head);
    
    curr=head;
    while(curr)
    {
        cout<<curr->val<<" ";
        curr=curr->next;
    }
}

int main()
{
ios_base::sync_with_stdio(false); cin.tie(0);
//freopen("i.txt","r",stdin);
//freopen("o.txt","w",stdout);
//li T;  cin>>T;  W(T--)
solve_this();
rr 0;
}


