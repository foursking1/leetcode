class RandomListNode:
    def __init__(self, x):
        self.label = x
        self.next = None
        self.random = None

class Solution:
    # @param head, a RandomListNode
    # @return a RandomListNode
    def copyRandomList(self, head):
        p1 = phead = RandomListNode(0)
        p2 = head
        map = {}
        while p2:
            node = RandomListNode(p2.label)
            map[p2] = node
            p1.next = node
            p1, p2 = p1.next, p2.next
        
        p2 = head
        while p2:
            if p2.random:
                map[p2].random = map[p2.random]
            p2 = p2.next
        return phead.next
        
        
        
            
        
        