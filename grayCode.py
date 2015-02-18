class Solution:
    # @return a list of integers
    def grayCode(self, n):
        self.res = [0]
        for i in [2**x for x in range(0, n)]:
            #self.res.append(self.res[-1] + i)
            self.res.extend([i + v for v in self.res[-1:None:-1]])
        return self.res;
        
s =Solution()
print s.grayCode(4)