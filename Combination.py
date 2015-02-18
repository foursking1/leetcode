class Solution:
    # @param candidates, a list of integers
    # @param target, integer
    # @return a list of lists of integers
    def combinationSum(self, candidates, target):
    	ret = []
    	maxsum = sum(candidates)
    	if maxsum < target:
    		return ret

    	if len(candidates) == 0:
    		return ret

    	if len(candidates) == 1:
    		if target == candidates[0]:
    			ret.append([target])
    			return ret
    		else:
    			return ret

    	ret1 = self.combinationSum(candidates[0:len(candidates)-1], target)
    	ret2 = self.combinationSum(candidates[0:len(candidates)-1], target - candidates[len(candidates-1)])
    	for i in range(len(ret2)):
    		ret2[i].append(target)

    	ret = ret1 + ret2
    	return ret
