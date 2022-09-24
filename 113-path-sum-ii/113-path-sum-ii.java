/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    List<List<Integer>> res = new ArrayList<>();
    
    void helper(TreeNode root, int sum, int target, List<Integer> path){
        if(root==null)return;
        if(root.left==null && root.right==null && sum==target){
            res.add(new ArrayList(path));
            return;
        }
        if(root.left!=null){
            path.add(root.left.val);
            helper(root.left, sum+root.left.val,target,path);
            int index = path.size()-1;
            path.remove(index);
        }
        if(root.right!=null){
            path.add(root.right.val);
            helper(root.right, sum+root.right.val,target,path);
            int index = path.size()-1;
            path.remove(index);
        }
    }
    
    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        List<Integer> path = new ArrayList<>();
        if(root==null)return res;
        path.add(root.val);
        helper(root,root.val,targetSum,path);
        return res;
    }
}