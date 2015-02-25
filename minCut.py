class Solution:
    # @param s, a string
    # @return an integer
    def minCut(self, s):
        lookup, mincut = [[False for j in range(len(s))] for i in range(len(s))], [0 for i in range(len(s))]
        for i in reversed(range(len(s))):
            for j in range(i, len(s)):
                if s[i] == s[j] and ( j - i < 2 or lookup[i+1][j-1]):
                    lookup[i][j] = True
                else:
                    lookup[i][j] = False
        
        for i in range(len(s)):
            minnum = 2147483647
            if lookup[0][i] == False:
                for j in range(i):
                    if lookup[j+1][i] == True:
                        minnum = min(minnum, mincut[j] + 1)
            else:
                minnum = 0
            mincut[i] = minnum
        return mincut[-1]

        
        
        
s = Solution()
a = 'aabaaa'
print s.minCut(a)