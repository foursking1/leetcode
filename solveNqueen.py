class Solution:
    # @return a list of lists of string
    def solveNQueens(self, n):
        res = []
        column = [0 for i in range(n)]
        rup = [0 for i in range(2 * n - 1)]
        lup = [0 for i in range(2 * n - 1)]
        queue = [-1 for i in range(n)]

        def backtrack(k):
            if k >= n:                
                mat = []
                for i in range(n):
                    rowstr = '.' * n
                    rowstr = rowstr[0:queue[i]] + 'Q' + rowstr[queue[i]+1:]
                    #rowstr[queue[i]] = 'Q'
                    mat.append(rowstr)
                    
                for i in range(n):
                   print mat[i]          
                res.append(mat)
                #print matrix
                #print mat
            else:          
                for i in range(0,n):
                    if column[i] == 0 and lup[i+k] == 0 and rup[n-1-i+k] == 0:
                        queue[k] = i
                        column[i] = 1
                        lup[i+k] = 1
                        rup[n-1-i+k] = 1
                        backtrack(k+1)
                        queue[k] = -1
                        column[i] = 0
                        lup[i+k] = 0
                        rup[n-1-i+k] = 0
        backtrack(0)
        return len(res)            
                
s = Solution()
print s.solveNQueens(4)
