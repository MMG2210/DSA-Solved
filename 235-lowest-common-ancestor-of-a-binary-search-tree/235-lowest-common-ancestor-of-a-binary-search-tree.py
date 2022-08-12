# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        
        def find(node, left, right):
            if node is None:
                return None
            
            if left<=node.val<=right:
                return node
            
            if right<node.val:
                return find(node.left,left,right)
            return find(node.right,left,right)
            
        return find(root,min(p.val,q.val),max(p.val,q.val))