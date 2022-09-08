# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        res, st = [], []
        while True:
            while root:
                st.append(root)
                root=root.left
            if not st:
                return res
            node = st.pop()
            res.append(node.val)
            root=node.right