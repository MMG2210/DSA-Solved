# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def addOneRow(self, root: Optional[TreeNode], val: int, depth: int) -> Optional[TreeNode]:
        if root==None:return root
        if depth==1:
            newNode = TreeNode(val)
            newNode.left=root
            return newNode
        
        def solve(root,val,depth,curDepth):
            if root==None: return
            if depth-1>curDepth:
                solve(root.left,val,depth,curDepth+1)
                solve(root.right,val,depth,curDepth+1)
                return
            newNode1, newNode2 = TreeNode(val), TreeNode(val)
            left,right=root.left,root.right
            root.left,root.right=newNode1,newNode2
            newNode1.left,newNode2.right=left,right
            return
        
        solve(root,val,depth,1)
        return root