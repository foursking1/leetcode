class Solution:
    # @param grid, a list of lists of integers
    # @return an integer
    def minPathSum(self, grid):
        m = len(grid)
        
        n = len(grid[0]) 
        
        dp = [[0] * n for _ in range(m)]  
        
        path = 0
        for i in range(n):
            dp[0][i] = path + grid[0][i]
            path = dp[0][i]
        
        path = 0    
        for j in range(m):
            dp[j][0] = path + grid[j][0]
            path = dp[j][0]
            
        for i in range(1,n):
            for j in range(1,m):
                dp[j][i] = min(dp[j-1][i] +  grid[j][i], dp[j][i-1] + grid[j][i])
        return dp[m-1][n-1]  
        
grid = [[1,2,3],[4,5,6],[7,8,9]]
s = Solution()
print s.minPathSum(grid)
            
            