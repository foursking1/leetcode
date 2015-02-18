
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @param head, a ListNode
    # @param m, an integer
    # @param n, an integer
    # @return a ListNode
    def reverseBetween(self, head, m, n):
        prem, pre, next, now, nowm = None, None, None, head, None
        ind = 1
        while now:
            next = now.next
            if ind >= m and ind <= n:
                now.next = pre
            if ind == m:
                prem, nowm = pre, now
            if ind == n:
                nowm.next = next
                if prem is None:
                    head = now
                else:
                    prem.next = now
                
            pre, now, ind = now, next, ind+1
        return head   