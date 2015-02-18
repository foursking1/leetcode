class Solution:
    # @return an integer
    def uniquePaths(self, m, n):
        if m == 0 and n == 0:
            return 0      
        grid = [[0] * n for _ in range(m)]
        for i in range(m):
            grid[i][0] = 1
        for j in range(n):
            grid[0][j] = 1
            
        for i in range(1,n):
            for j in range(1,m):
                grid[j][i] = grid[j-1][i] + grid[j][i-1]
        return grid[m-1][n-1]
            
            

s = Solution()
print s.uniquePaths(2,3)