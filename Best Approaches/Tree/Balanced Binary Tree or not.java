/**
 * Definition for binary tree
 * class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) {
 *      val = x;
 *      left=null;
 *      right=null;
 *     }
 * }
 */

/*Given a binary tree, determine if it is height-balanced.*/

//1st approach
class Height {
    int height;
    
    Height() {
        this.height=0;
    }
}
public class Solution {
    private boolean isBalancedUtil(TreeNode A,Height h) {
        if(A==null) {
            h.height=0;
            return true;
        }
        
        Height lh=new Height();
        Height rh=new Height();
        
        boolean l=isBalancedUtil(A.left,lh);
        boolean r=isBalancedUtil(A.right,rh);
        
        h.height=Math.max(lh.height,rh.height)+1;
        
        if(Math.abs(lh.height-rh.height)>1) {
            return false;
        }
        
        return l && r;
    }
    
    public int isBalanced(TreeNode A) {
        Height h=new Height();
        return isBalancedUtil(A,h) == true ? 1 : 0;
    }
}


//2nd approach
public class Solution {
    int chk=1;
    private int isBalancedUtil(TreeNode A) {
        if(A==null || chk==0)
            return 0;
    
        int u=isBalancedUtil(A.left);
        int v=isBalancedUtil(A.right);
        
        if(Math.abs(u-v)>1)
        {
            chk=0;
            return 0;
        }
            
        return Math.max(u,v)+1;
    }
    
    public int isBalanced(TreeNode A) {
        isBalancedUtil(A);
        return chk;
    }
}

