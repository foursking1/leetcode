
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    # @param root, a tree node
    # @param sum, an integer
    # @return a boolean
    def hasPathSum(self, root, sum):
        if root is None:
            return False
        
        # base situation
        # is node is leaf
        if root and root.left is None and root.right is None:
            if sum == root.val:
                return True
            else:
                return False
                
        if root.left and self.hasPathSum(root.left, sum - root.val):
            return True
        
        if root.right and self.hasPathSum(root.right, sum - root.val):
            return True
        
        return False
            