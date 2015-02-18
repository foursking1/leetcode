
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @param head, a list node
    # @return a tree node
    def sortedListToBST(self, head):

        if head is None:
            return head
        #find mid
        pre, p , p1 = None, head, head
        while p1 and p1.next:
            pre = p
            p = p.next
            p1 = p1.next.next
            
        root = TreeNode(p.val)
        #set pre list end to None
        if pre is None:
            head = None
        else:
            pre.next = None

        root.left = self.sortedListToBST(head)
        root.right = self.sortedListToBST(p.next)
        return root
        

head = ListNode(0)
s = Solution()
#print 'aaa'
s.sortedListToBST(head)
        
        
        
        
        