class Solution:
    # @return an integer
    def numTrees(self, n):
        if n == 0:
            return 1
        if n == 1:
            return 1
        if n == 2:
            return 2
        res = 0
        for i in range(1, n+1):
            res += self.numTrees(i-1) * self.numTrees(n-i)
            #print i, res
            
        return res
        
s = Solution()
print s.numTrees(3)
            