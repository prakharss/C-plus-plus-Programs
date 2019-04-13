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

node* removeNode(node *prev,node *remove,node *head)
{
    node *temp;
    if(head==remove)
    {
        temp=head;
        delete(head);
        head=temp->next;
    }
    else
    {
        prev->next=remove->next;
        delete(remove);
    }
    
    return head;
}

node* removeAllDuplicates(node *head)
{	
    int t;
	node *curr,*prev;
    
    curr=head;
    prev=NULL;
    
    while(curr && curr->next)
    {
        if(curr->val == curr->next->val)
        {
            t=curr->val;
            while(curr!=NULL && curr->val==t)
            {
                head=removeNode(prev,curr,head);
                curr=curr->next;
            }
        }
        else
        {
            prev=curr;
            curr=curr->next;
        }
    }
    
    return head;
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
	
	head=removeAllDuplicates(head);
    
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


