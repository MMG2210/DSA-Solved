# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
        res,q = [],[root]
        while(len(q)):
            sz = len(q)
            avg = 0
            for i in range(sz):
                front = q.pop(0)
                if front.left:
                    q.append(front.left)
                if front.right:
                    q.append(front.right)
                avg+=front.val
            avg/=sz
            res.append(avg)
        return res