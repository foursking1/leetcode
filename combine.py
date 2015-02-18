class Solution:
    # @return a list of lists of integers
    def combine(self, n, k):
        ans = []
        num = []
        def dfs(depth, lnum):
            #print depth,lnum
            if depth == k:
                lnum = lnum[:]
                ans.append(lnum)
                return 
            
            if len(lnum) == 0:
                start = 1 
            else:
                start = lnum[len(lnum)-1]+1
            
            for i in range(start,n+1):
                tmp = lnum[:]
                tmp.append(i)
                dfs(depth+1,tmp)
        
        dfs(0,num)
        return ans
#num = []
#print len(num)        
s = Solution()
print s.combine(4,2)
                