class Solution:
    # @param candidates, a list of integers
    # @param target, integer
    # @return a list of lists of integers
    def combinationSum(self, candidates, target):
        ans = []
        candidates.sort()
        for ii,elem in enumerate(candidates):
            if target > elem:
                # eliminate duplicate
                subSet = self.combinationSum(candidates[ii:],target-elem)
                if subSet:
                    ans += [[elem]+lis for lis in subSet]
            elif target == elem:
                ans += [[elem]]
            else:
                break
        return ans
                
s = Solution()
a = [1,2]
target = 2
print s.combinationSum(a,target)