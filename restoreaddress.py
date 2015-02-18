class Solution:
    # @param s, a string
    # @return a list of strings
    def restoreIpAddresses(self, s):
        self.ret = []
        self.s = s
        self.dfs(0, '', 0)
        return self.ret
        
    def dfs(self, k, ans , lens):
        if k == 4:
            if lens == len(self.s):
                self.ret.append(ans)
            return
        else:
            for i in range(1,4):
                tmp = self.s[lens:lens+i]
                if tmp == '':
                    tmp = 0
                else:
                    tmp = int(tmp)
                
                if (i == 1 and tmp >= 0 and tmp <= 9) or\
                    (i == 2 and tmp >= 10 and tmp <= 99) or\
                    (i == 3 and tmp >= 100 and tmp <= 255):
                    if k == 0:
                        val = ans[:] + self.s[lens:lens+i];
                    else:
                        val = ans[:] + '.' + self.s[lens:lens+i];
                    self.dfs( k+1,val, lens + i)
             
   
s = Solution()
print s.restoreIpAddresses('0001')