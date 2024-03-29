# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        
        def helper(root,minVal=-inf,maxVal=inf):
            if root is None: 
                return True
            if root.val<=minVal or root.val>=maxVal:
                return False
            return helper(root.left,minVal,root.val) and helper(root.right,root.val,maxVal)
        
        return helper(root)
        