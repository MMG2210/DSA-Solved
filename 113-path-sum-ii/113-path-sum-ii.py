# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, R: TreeNode, S: int) -> List[List[int]]:
        A, P = [], []
        def dfs(N):
            if N == None: return
            P.append(N.val)
            if (N.left,N.right) == (None,None) and sum(P) == S: A.append(list(P))
            else: dfs(N.left), dfs(N.right)
            del P[-1]
        dfs(R)
        return A