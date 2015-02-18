class Solution:
    # @param A, a list of integers
    # @return a boolean
    def canJump(self, A):
        length = len(A)
        begin = length - 1

        for i in reversed(range(length - 1)):
            print i
            if i + A[i] >= begin:
                begin = i

        return not begin   

            
s = Solution()
A = [3,1,2,3,4]
print s.canJump(A)
