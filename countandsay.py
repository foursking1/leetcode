class Solution:
    # @return a string
    def countAndSay(self, n):
        if n == 1:
            return '1'
        if n == 2:
            return '11'
        s = self.countAndSay(n-1)
        
        ret = ""
        laststr = s[0]
        count = 1
        for i in range(len(s)):
            #print s[i]
            if i == 0:
                continue
            if s[i] == laststr:
                count += 1
            else:
                ret += str(count) + laststr
                count = 1
                laststr = s[i]
                
        ret += str(count) + laststr 
        return ret
       
s = Solution()
print s.countAndSay(6)      
        