class Solution:
    # @param S, a list of integer
    # @return a list of lists of integer
    def subsets(self, S):
        self.ans = []
        self.num = sorted(S)
        n = len(self.num)
        ori = []
        self.dfs(-1,n,ori)
        return self.ans
        
    def dfs(self,k,n,tmp):
        self.ans.append(tmp[:])
        
        for i in range(k+1,n): 
            tmp.append(self.num[i])      
            self.dfs(i,n,tmp)
            tmp.pop()

s = Solution()
S = [1,2,3]
print s.subsets(S)