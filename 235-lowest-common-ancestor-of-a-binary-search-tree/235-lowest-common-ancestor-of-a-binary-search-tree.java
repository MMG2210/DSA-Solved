/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

class Solution {
    public TreeNode lca(TreeNode node, int min, int max){
        if(node==null)return node;
        if(min<=node.val && node.val<=max)return node;
        if(max<node.val)return lca(node.left,min,max);
        return lca(node.right,min,max);
    }
    
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        return lca(root, Math.min(p.val,q.val), Math.max(p.val,q.val));
    }
}