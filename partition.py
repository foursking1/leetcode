class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @param head, a ListNode
    # @param x, an integer
    # @return a ListNode
    def partition(self, head, x):
        if not head:
            return 
            
        
        ps = pshead = ListNode(0)
        pl = plhead = ListNode(0)
        
        p = head
        
        while p:
            #print p.val
            if p.val >= x:
                pl.next = p
                pl = pl.next
            else:
                ps.next = p
                ps = ps.next
            p = p.next
        
        #if pl.next:
        pl.next = None
        ps.next = plhead.next
        return pshead.next   
        
s = Solution() 

head = p = ListNode(2) 
head.next = ListNode(1)
#print 'aaa'
ret =  s.partition(head, 2)
while ret:
    print ret.val
    ret = ret.next

        