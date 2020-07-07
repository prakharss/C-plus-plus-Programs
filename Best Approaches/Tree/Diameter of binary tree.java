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
 
class Height {
    int height;
} 
public class Solution {
    private int diameterOfBinaryTree(TreeNode A,Height h) {
        if(A==null) {
            h.height=0;
            return 0;
        }
        
        Height lh=new Height();
        Height rh=new Height();
        
        int ld=diameterOfBinaryTree(A.left,lh);
        int rd=diameterOfBinaryTree(A.right,rh);
        
        h.height=Math.max(lh.height,rh.height)+1;
        return Math.max(lh.height+rh.height+1,Math.max(ld,rd));
    }
    
    public int solve(TreeNode A) {
        Height h=new Height();
        return diameterOfBinaryTree(A,h)-1;
    }
}