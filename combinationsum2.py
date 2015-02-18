import unittest

class Solution:
    # @param candidates, a list of integers
    # @param target, integer
    # @return a list of lists of integers
    def combinationSum(self, candidates, target):
        ans = []
        candidates.sort()
        def search(candidates, next, sol, target, result):
            #need copy
            #all is reference
            sol = sol[:]
            if target == 0:
                result += [sol]
                return
            if next == len(candidates) or target - candidates[next] < 0 :
                return 
            
            sol += [candidates[next]]
            search(candidates, next, sol, target - candidates[next], result)
            sol = sol[0:len(sol)-1]
    
            
            search(candidates, next+1, sol, target, result)
        sol = []
        search(candidates, 0, sol, target, ans)
        return ans

#class test(unittest.TestCase):
#    def testex(self):
#        sol = Solution()
#        self.assertEqual(sol.combinationSum([2,3,4,6],7),[[2,2,3],[7]])
#        self.assertEqual(sol.combinationSum([2,3,4,6],7),[[2,2,3],[2]])
#
#unittest.main()        
                            
s = Solution()
a = [1,2]
target = 4
print s.combinationSum(a,target) 