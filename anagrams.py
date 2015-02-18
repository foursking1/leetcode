class Solution:
    # @param strs, a list of strings
    # @return a list of strings
    def anagrams(self, strs):
        res = []
        anagrams = dict()
        for value in strs:
            r = sorted(value)
            if str(r) not in anagrams:
                anagrams[str(r)] = 0
            else:
                anagrams[str(r)] += 1
        
        for value in strs:
            r = sorted(value)
            if anagrams[str(r)] > 0:
                res.append(value)
        
        return res
            
            

anastr = ['tea','tae','and']
s = Solution()
print s.anagrams(anastr)