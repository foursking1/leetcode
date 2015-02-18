class Solution:
    # @param A, a list of integers
    # @return an integer
    def trap(self, A):
        left = 0
        right = len(A)-1
        leftmax = 0
        rightmax = 0
        store = 0
        while left <= right:
            leftmax = max(leftmax, A[left])
            rightmax = max(rightmax, A[right])
            if leftmax < rightmax:
                store += leftmax - A[left]
                left += 1
            else:
                store += rightmax - A[right]
                right -= 1
                
        return store
                
                    
a = [0,1,0,2,1,0,1,3,2,1,2,1]
s = Solution()
print s.trap(a)
                
