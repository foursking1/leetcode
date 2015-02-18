class Solution:
    # @param x, an integer
    # @return an integer
    def sqrt(self, x):
        y0, y1 = 0, 1
        while int(y0) != int(y1):
            y0 = y1
            y1 = 1.0/2.0 * (y0 + x / y0)
        return int(y0)
        
s = Solution()
num = 2147395599
print s.sqrt(num)