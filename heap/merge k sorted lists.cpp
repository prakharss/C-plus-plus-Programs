/*
merge k sorted lists
you can test the solution in interview bit
O(n*k*log(k)) S(k) where n = n1 + n2 + n3 + n4 + n5 + so on
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* createNode(int value)
{
    ListNode *node;
    node=new ListNode(value);
    
    return node;
}
 
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    int i,chk,pos,value,k;
    k=A.size();
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq; 
    
    for(i=0;i<k;i++)
        pq.push(make_pair(A[i]->val,i));
    
    chk=0; ListNode *head,*traversal,*node;
    while(!pq.empty())
    {
        pair<int,int> temp=pq.top();
        value=temp.first; pos=temp.second;
        pq.pop();
        
        node=createNode(value);
        if(!chk)
        {
            head=node;
            traversal=head;
            chk=1;
        }
        else
        {
            traversal->next=node;
            traversal=node;
        }
        
        A[pos]=A[pos]->next;
        if(A[pos])
            pq.push(make_pair(A[pos]->val,pos));
    }
    
    return head;
}