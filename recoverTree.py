
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    # @param root, a tree node
    # @return a tree node
    def recoverTree(self, root):
        self.pre = None
        self.n1 = self.n2 = None
        self.dfs(root)
        self.n1.val, self.n2.val = self.n2.val, self.n1.val
        return root
        
    def dfs(self, root):
        if not root:
            return 
        self.dfs(root.left)
        if self.pre and root.val < self.pre.val:
            if not self.nt:
                self.n1, self.n2 = self.pre, root
            else:
                self.n2 = root
        self.pre = root
        self.dfs(root.right)
        