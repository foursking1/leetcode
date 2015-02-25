class Solution:
    # @param s, a string
    # @param dict, a set of string
    # @return a boolean
    def wordBreak(self, s, dict):
        n = len(s)
        f = [False for _ in xrange(n)]
        trace = [[False] * n for _ in xrange(n)]
        for i in xrange(n):
            if s[:i+1] in dict:
                f[i] = True
                trace[0][i] = True
            for j in xrange(i):
                if f[j] and s[j+1:i+1] in dict:
                    f[i] = True
                    trace[j+1][i] = True
        result = []
        if f[n-1]:
            self.backtrack(s, trace, 0, [], result)
        return result
    
    def backrack(self, s, trace, start, path, result):
        if start == len(s):
            result.append(" ".join(path))
            return 
        for i in xrange(start, len(s)):
            if trace[start][i]:
                self.backtrack(s, trace, i + 1, path + [s[start:i+1]],result)
                
str = "catsanddog"
dict = ["cat", "cats", "and", "sand", "dog"]
s = Solution()
print s.wordBreak(str, dict)
            

