#include<bits/stdc++.h>
using namespace std;
typedef long long int li;

struct Node
{
	int val;
	Node *next;
};

Node* createNode(int val)
{
	Node *node=new Node;
	node->val=val;
	node->next=NULL;
	
	return node;
}

int palindrome(Node *head)
{	
	int len=0,chk=1,i;
    
    Node *temp;
    temp=head;
	while(temp!=NULL)
	{
		len++;
		temp=temp->next;
	}
	
    temp=head;
	for(i=0;i<len/2;i++)
        temp=temp->next;
    
    Node *temp1,*curr,*prev;
    curr=temp; prev=NULL;
    while(curr)
    {
        temp1=curr->next;
        curr->next=prev;
        
        prev=curr;
        curr=temp1;
    }
    
    Node *newhead=prev;
    temp=head; temp1=newhead;
    for(i=0;i<len/2;i++)
    {
        if(temp->val!=temp1->val)
        {
            chk=0;
            break;
        }
        
        temp=temp->next;
        temp1=temp1->next;
    }
    
    return chk;
}

int main()
{
	li n,i,t,val;
	Node *head,*curr;
	
	cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>t;
        if(i==0)
        {
            head=createNode(t);
            curr=head;
        }
        else
        {
            TreeNode *temp;
            temp=createNode(t);
            curr->next=temp;
            curr=temp;
        }
    }
	
	if(palindrome(head))
		cout<<"yes";
	else
		cout<<"no";

	return 0;
}



