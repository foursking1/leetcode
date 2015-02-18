
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


#class Solution:
#    # @param preorder, a list of integers
#    # @param inorder, a list of integers
#    # @return a tree node
#    def buildTree(self, preorder, inorder):
#        
#        def dfs(preorder, inorder):
#            if len(preorder) == 0:
#                return None
#            if len(inorder) == 0:
#                return None
#                
#            root = TreeNode(preorder[0])
#            print root.val
#            
#            posi = inorder.index(preorder[0])
#            root.left = dfs(preorder[1:1 + posi], inorder[0:posi])
#            root.right = dfs(preorder[posi+1:],inorder[posi+1:])
#            
#            return root
#        return dfs(preorder, inorder)
class Solution:
    def buildTree(self, preorder, inorder):
        # using dictionary for index lookup improves the performance of algorithm from O(N^2) to O(N), where N = |preorder|
        lookup = {}
        for i in range(len(inorder)):
            lookup[inorder[i]] = i 
        return self.buildTreeRecur(lookup, preorder, inorder, 0, len(preorder) - 1, 0)
        
    def buildTreeRecur(self, lookup, preorder, inorder, in_start, in_end, pre_start):
        if in_start > in_end:
            return None
        current = TreeNode(preorder[pre_start])
        i = lookup[preorder[pre_start]]
        current.left = self.buildTreeRecur(lookup, preorder, inorder, in_start, i - 1, pre_start + 1)
        current.right = self.buildTreeRecur(lookup, preorder, inorder, i + 1, in_end, pre_start + i - in_start + 1)
        return current
#        
s = Solution()
s.buildTree([3,1,2,6,4,7],[1,3,2,4,6,7])
