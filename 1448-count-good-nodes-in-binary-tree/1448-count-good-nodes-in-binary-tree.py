# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        res = []
        
        def count(root, maxi):
            if root==None:
                return
            
            if root.val>=maxi:
                res.append(root)
                maxi=root.val
            
            count(root.left,maxi)
            count(root.right,maxi)
            
        count(root,-100000)
        return len(res)