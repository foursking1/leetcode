class Solution:
    # @param num, a list of integer
    # @return a list of lists of integer
    def subsetsWithDup(self, S):
        self.ans = []
        self.S = sorted(S)
        subset =[]
        self.dfs(subset, 0)
        return self.ans
        
    def dfs(self, subset, k):
        #print k, subset
        self.ans.append(subset)
        
        if k >= len(self.S):
            return
            
        stk = [] 
        for i in range(k, len(self.S)):
            if len(stk) == 0 or stk[-1] != self.S[i] :
                stk.append(self.S[i])
                tmp = subset[:]
                tmp.append(self.S[i])
                self.dfs(tmp, i+1)
                
s = Solution()
print s.subsetsWithDup([4,1,0])
    