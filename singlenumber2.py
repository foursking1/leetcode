class Solution:
    # @param A, a list of integer
    # @return an integer
    def singleNumber(self, A):
        one, two, three = 0, 0, 0
        for ai in A:
            three = two & ai
            two = ( two | (one & ai)) & ( ~three )
            one = ( one | ai ) & ( ~three)
            
        return one
        
A = [1,1,1,2,2,3,4,3,3,2]
s = Solution()
print s.singleNumber(A)