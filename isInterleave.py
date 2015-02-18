class Solution:
    # @return a boolean
    def isInterleave(self, s1, s2, s3):
        ls1 = len(s1)
        ls2 = len(s2)
        ls3 = len(s3)
        
        if ls1 + ls2 != ls3:
            return False
        dp = [ [False] * (ls2+1) for _ in range(ls1+1) ]    
        dp[0][0] = True
                
        for i in range(ls1+1):
            for j in range(ls2+1):
                if i > 0 and dp[i-1][j] and s1[i-1] == s3[i+j-1]:
                    dp[i][j] = True
                
                if j > 0 and dp[i][j-1] and s2[j-1] == s3[i+j-1]:
                    dp[i][j] = True
        
        #print dp
        return dp[ls1][ls2]
        
s = Solution()
print s.isInterleave('aabcc','dbbca','aadbbbaccc')
            