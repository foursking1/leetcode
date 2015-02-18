class Solution:
    # @return a boolean
    def isScramble(self, s1, s2):
        if len(s1) != len(s2):
            return False
        if len(s1) == 0:
            return True
        self.s1, self.s2 = s1, s2
        lens = len(s1)
        self.dp = [[[-1] * lens for i in range(lens)] * lens for i in range(lens)]
        return self.dfs(0, 0, len(s1))
    
    def dfs(self, lp, rp, len):
        if self.dp[lp][rp][len - 1] >= 0:
            return True if self.dp[lp][rp][len - 1] == 1 else False
        if len == 1:
            return self.s1[lp] == self.s2[rp]
        for i in range(1, len):
            if self.dfs(lp, rp, i) and self.dfs(lp + i, rp + i, len - i) \
                    or self.dfs(lp, rp + len - i, i) and self.dfs(lp + i, rp, len - i):
                self.dp[lp][rp][len - 1] = 1
                return True
        self.dp[lp][rp][len - 1] = 0 
        return False
s = Solution()
print s.isScramble('abcdefghijklmnopq','efghijklmnopqcadb')