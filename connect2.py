class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
        self.next = None

class Solution:
    # @param root, a tree node
    # @return nothing
    def connect(self, root):
        if root == None:
            return
        dummy = TreeNode(0)
        cur = root
        while cur != None:
            ptr = dummy
            dummy.next = None
            while cur != None:
                if cur.left != None:
                    ptr.next = cur.left
                    ptr = ptr.next
                if cur.right != None:
                    ptr.next = cur.right
                    ptr = ptr.next
                cur = cur.next
            cur = dummy.next
        return