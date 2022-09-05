"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        res = []
        if root==None:return res
        q = deque()
        q.append(root)
        while len(q)>0:
            temp = []
            sz = len(q)
            for i in range(sz):
                node = q.popleft()
                temp.append(node.val)
                for child in node.children:
                    q.append(child)
            res.append(temp)
        return res