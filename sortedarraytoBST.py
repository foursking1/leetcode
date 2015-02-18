 
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    # @param num, a list of integers
    # @return a tree node
    def sortedArrayToBST(self, num):     
        lenn = len(num)
        if lenn == 0:
            return None 
        mid = lenn//2    
        root = TreeNode(num[mid])
        root.left = self.sortedArrayToBST(num[0:mid])
        root.right = self.sortedArrayToBST(num[mid+1:])
        return root