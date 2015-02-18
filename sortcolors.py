class Solution:
    # @param A a list of integers
    # @return nothing, sort in place
    def sortColors(self, A):
        s, t, e = 0, 0, len(A) - 1
        while s <= e:
            if A[s] == 0:
                if s != t:
                    A[s], A[t] = A[t], A[s]
                s, t = s + 1, t + 1
            elif A[s] == 1:
                s = s + 1
            elif A[s] == 2:
                if s != e:
                    A[s], A[e] = A[e], A[s]
                e = e - 1
        return A
                
s = Solution()
A = [2,1,0]
s.sortColors(A)
print A  
            