
class Solution:
    # @return a list of tree node
    def generateTrees(self, n):
        return self.dfs(0, n)
        
    def dfs(self, l , r):
        ans = []
        if l == r:
            ans.append(None)
            return ans
        for i in range(l, r):
            lb , rb = self.dfs(l,i), self.dfs(i+1, r)
            for lc in lb:
                for rc in rb:
                    node = TreeNode(i+1)
                    node.left = lc
                    node.right = rc
                    ans.append(node)
        return ans