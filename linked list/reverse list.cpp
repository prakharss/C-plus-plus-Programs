#include<bits/stdc++.h>
using namespace std;

struct Node
{
    Node *next;
    int val;
};

Node* createNode(int val)
{
	Node *node=new Node;
	node->val=val;
	node->next=NULL;
	
	return node;
}

Node* reverseListByIteration(Node *head)
{
    Node *prev=NULL,*curr=head;
    while(curr)
    {
        Node *temp;
        temp=curr->next;
        curr->next=prev;
        prev=curr;
        
        curr=temp;
    }
    
    head=prev;
    return head;
}

Node* reverseListByRecursion(Node *prev,Node *curr)
{
    if(curr)
    {
        Node *temp=curr->next;
        curr->next=prev;
        return reverseListByRecursion(curr,temp);
    }
    
    return prev;
}

/*Node* reverseListByRecursion(Node *prev,Node *curr)
{
	Node *head;
    if(curr)
    {
        Node *temp=curr->next;
        curr->next=prev;
        head=reverseListByRecursion(curr,temp);
    }
    else
    	return prev;

    return head;
}*/

int main()
{   
    int i,n,t;
    Node *head,*temp,*curr;                              
    
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
            temp=createNode(t);
            curr->next=temp;
            curr=temp;
        }
    }
    
    head=reverseListByIteration(head);
    
    temp=head;
    while(temp)
    {
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    
    head=reverseListByRecursion(NULL,head); cout<<"\n";
    
    temp=head;
    while(temp)
    {
        cout<<temp->val<<" ";
        temp=temp->next;
    }
}

