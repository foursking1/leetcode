
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None



class Solution:
    # @param root, a tree node
    # @param sum, an integer
    # @return a list of lists of integers
    def pathSum(self, root, sum):
        self.ret = []
        self.dfs(root,sum,[])
        return self.ret
    
    def dfs(self, root , sum, ans):
        if root is None:
            return False
        
        # base situation
        # is node is leaf
        ans.append(root.val)
        if root and root.left is None and root.right is None:
            if sum == root.val:          
                self.ret.append(ans)         

        if root.left:
            self.dfs(root.left, sum - root.val, ans)

        if root.right:
            self.dfs(root.right, sum - root.val, ans)
        
        return False
        
        
        
class Solution:
    def pathSum(self, root, sum):
        return self.pathSumRecur([], [], root, sum)
        
    def pathSumRecur(self, result, path, root, sum):
        if root is None:
            return result
        if root.left is None and root.right is None and root.val == sum:
            return result + [path + [root.val]]
        return self.pathSumRecur(result, path + [root.val], root.left, sum - root.val) + self.pathSumRecur(result, path + [root.val], root.right, sum - root.val)
