class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @param two ListNodes
    # @return a ListNode
    def mergeTwoLists(self, l1, l2):
        head = ListNode(0)
        ptr = head
        i = 0
        while l1 or l2:
            print i
            if l1 and not l2:
                ptr.next, l1 = l1, l1.next
                ptr = ptr.next
            elif l2 and not l1:
                ptr.next, l2 = l2, l2.next
                ptr = ptr.next
            elif l1.val < l2.val:
                ptr.next, l1 = l1, l1.next
                ptr = ptr.next
            else:
                ptr.next, l2 = l2, l2.next
                ptr = ptr.next
            i += 1
        return head.next  
l1 = ListNode(1)
l2 = ListNode(2)
s = Solution()
res = s.mergeTwoLists(l1,l2)

while res:
    print res.val
    res = res.next
   
       