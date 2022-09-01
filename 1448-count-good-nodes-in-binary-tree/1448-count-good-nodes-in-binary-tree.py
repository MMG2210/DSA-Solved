# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        def count(root, maxi):
            if root==None:
                return 0
            
            good=0
            if root.val>=maxi:
                good=1
            maxi=max(root.val,maxi)
            
            return good+count(root.left,maxi)+count(root.right,maxi)
            
        return count(root,-100000)
        