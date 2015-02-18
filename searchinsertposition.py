import unittest

class Solution:
    # @param A, a list of integers
    # @param target, an integer to be inserted
    # @return integer
    def searchInsert(self, A, target):
        #if target < A[0] and len(A) > 0:
         #   return 0      
        def get(start, end):
            if start > end:
                return -1  
            mid = (start + end)/2
            if A[mid] == target:
                return mid
            elif A[mid] > target:
                if start == end:
                    return mid
                return get(start, mid)
            else:
                if start == end:
                    return mid+1
                return get(mid+1, end)
        
        return get(0, len(A)-1)

class Test(unittest.TestCase):
    
    def test(self):
        
        s = Solution()
        

s = Solution()
a = [1,3]
target = 4
print s.searchInsert(a,target)
            