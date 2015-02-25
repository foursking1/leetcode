class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    # @param root, a tree node
    # @return an integer
    def sumNumbers(self, root):
        self.res = 0
        self.dfs( 0, root)
        return self.res
        
    def dfs(self, sum, root):
        if root
        #find leaf
        if root.left is None and root.right is None:
            self.res += ( 10 * sum + root.val)
            
        else:
            if root.left:
                self.dfs( 10 * sum + root.val, root.left)
            if root.right:
                self.dfs( 10 * sum + root.val, root.right)
                
root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(3)
s = Solution()
print s.sumNumbers(root)
            
        