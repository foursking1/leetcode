class Solution:
    # @param x, a float
    # @param n, a integer
    # @return a float
    def pow(self, x, n):
        if n == 1:
            return x
        elif n % 2 == 0:
            res = pow(x, n/2)
            return res*res
        else:
            res = pow(x, n/2)
            return res*res*x

s = Solution()
num = 2.2
time = 4
print s.pow(num, time)       
        
            