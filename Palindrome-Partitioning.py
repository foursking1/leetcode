class Solution:
    # @param s, a string
    # @return a list of lists of string
    def partition(self, s):
        self.res = []
        self.dfs(0, s, [])
        return  self.res
            
    def dfs(self, start, s, num):
        n = len(s)
        if start == n:
            self.res.append(num)
            return 
        
        for i in range(start+1, n+1):
            #print s[start:i],i
            if self.isPalindrome(s[start:i]):
                a = num[:]
                a.append(s[start:i])
                self.dfs(i, s, a)
            
            
    def isPalindrome(self, s):
        if len(s) == 1:
            return True
            
        i,j = 0, len(s)-1
        while i < j:
            if s[i] != s[j]:
                return False
            i,j = i+1, j-1
        return True
        
s = Solution()
a = 'aaaabbb'
print s.partition(a)
        
        
    