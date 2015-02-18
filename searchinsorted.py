class Solution:
    # @param A, a list of integers
    # @param target, an integer to be searched
    # @return an integer
    def search(self, A, target):
        def get(start, end):
            mid = (start + end)/2
            if A[mid] == target:
                return mid;
            elif A[mid] >= A[start]:
                if target >= A[start] and target < A[mid]:
                    return get(start, mid-1)
                else:
                    return get(mid+1,end)
            elif A[mid] <= A[end]:
                if target >= A[mid] and target <= A[end]:
                    return get(mid+1,end)
                else:
                    return get(start, mid-1)
        return get(0, len(A)-1)
        
s = Solution()
a = [4,5,6,7,8,1,2,3]
target = 5
print s.search(a,target)