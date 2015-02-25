class Solution:
    # @param num, a list of integer
    # @return an integer
    def longestConsecutive(self, num):
        hashmap = dict()
        maxlength = 0
        for val in num:
            if val in hashmap:
                continue
            
            if val + 1 in hashmap:
                hashmap[val] = hashmap[val+1] + 1
            else:
                hashmap[val] = 1
            maxlength = max(hashmap[val], maxlength)
                
            if val - 1 in hashmap:
                index = val - 1
                while index in hashmap:
                    hashmap[index] += hashmap[val]
                    index -= 1
                maxlength = max(hashmap[index+1], maxlength)
                
        return maxlength
        
s = Solution()
num = [1,2,0,1]
print s.longestConsecutive(num)
        
                
                
        
        