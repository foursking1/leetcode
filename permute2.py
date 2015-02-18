class Solution:
    # @param num, a list of integer
    # @return a list of lists of integers
    def permuteUnique(self, num):
        res = []
        def search(num, k):
            if k == len(num):
                tmp = num[:]
                res.append(tmp)
            else:
                numSet = set()
                for i in range(k, len(num)):
                    
                    if num[i] not in numSet:
                        #print k
                        numSet.add(num[i])
                        tmp = num[k]
                        num[k] = num[i]
                        num[i] = tmp
                        search(num, k+1)
                        tmp = num[k]
                        num[k] = num[i]
                        num[i] = tmp
        search(num,0)
        return res      

a = [1, 2, 2,1]
s = Solution()
print s.permuteUnique(a)
                    