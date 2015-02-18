
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    # @param root, a tree node
    # @return a list of integers
    def inorderTraversal(self, root):
        res = []
        if not root:
            return res
        stk = []
        
        stk.append(root)
        while len(stk):
            node = stk[-1]
           
            if node.left:
                stk.append(node.left)
                node.left = None
            else:
                res.append(node.val)
                stk.pop()
                if node.right:    
                    stk.append(node.right)
        return res
        