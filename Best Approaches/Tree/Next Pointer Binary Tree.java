/**
 * Definition for binary tree with next pointer.
 * public class TreeLinkNode {
 *     int val;
 *     TreeLinkNode left, right, next;
 *     TreeLinkNode(int x) { val = x; }
 * }
 */

/*
Populate each next pointer to point to its next right node. 
If there is no next right node, the next pointer should be set to NULL.
Initially, all next pointers are set to NULL
*/

public class Solution {
    public void connect(TreeLinkNode root) {
        if(root==null) {
            return ;
        }
        
        TreeLinkNode head=root,temp=null,curr=null;
        while(head!=null) {
            curr=head;
            head=null;
            
            while(curr!=null) {
                if(curr.left!=null) {
                    if(head==null) {
                        head=temp=curr.left;
                    }
                    else {
                        temp.next=curr.left;
                        temp=temp.next;
                    }
                }   
                
                if(curr.right!=null) {
                    if(head==null)
                        head=temp=curr.right;
                    else {
                        temp.next=curr.right;
                        temp=temp.next;
                    }
                }
                
                curr=curr.next;
            }
        }
        
        return ;
    }
}
