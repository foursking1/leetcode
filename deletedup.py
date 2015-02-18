
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @param head, a ListNode
    # @return a ListNode
    def deleteDuplicates(self, head):
        if not head:
            return head
        nhead = ListNode(0)
        nhead.next, head = head, nhead
        while head:
            if head.next and head.next.next and head.next.next.val == head.next.val:
                head.next = head.next.next
            else:
                head = head.next
                
        return nhead.next