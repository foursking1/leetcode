class Solution:
    # @param A a list of integers
    # @return an integer
    def removeDuplicates(self, A):
        sz = 0
        for i in range(len(A)):
            if sz < 2 or A[sz - 2] != A[i]:
                A[sz] = A[i]
                sz = sz + 1
        return sz
        

s = Solution()
A = [1,1,1,1,2,2,3,3,4]
print s.removeDuplicates(A)
print A         
        