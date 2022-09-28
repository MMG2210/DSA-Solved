# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        f,s=head,head
        for _ in range(n): f=f.next      
        if not f: return head.next
        while f.next: f,s = f.next,s.next
        s.next=s.next.next
        return head