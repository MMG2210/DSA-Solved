# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        f=head
        s=head
        for i in range(n):
            f=f.next
        if f is None: return head.next
        while f.next is not None:
            f=f.next
            s=s.next
        s.next=s.next.next
        return head