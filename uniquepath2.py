class Solution:
    # @param obstacleGrid, a list of lists of integers
    # @return an integer
    def uniquePathsWithObstacles(self, obstacleGrid):
        m = len(obstacleGrid)
        
        n = len(obstacleGrid[0]) 
        
        grid = [[0] * n for _ in range(m)]
        
        obstacled = 0
        for i in range(n):
            if obstacleGrid[0][i] == 0 and obstacled == 0:
                grid[0][i] = 1
            elif obstacleGrid[0][i] == 1:
                grid[0][i] = 0
                obstacled = 1
            else:
                grid[0][i] = 0 
                
        obstacled = 0        
        for j in range(m):
            if obstacleGrid[j][0] == 0 and obstacled == 0:
                grid[j][0] = 1
            elif obstacleGrid[j][0] == 1:
                grid[j][0] = 0
                obstacled = 1
            else:
                grid[j][0] = 0 
                
        for i in range(1,n):
            for j in range(1,m):
                if obstacleGrid[j][i] == 1:
                    grid[j][i] == 0
                else:
                    grid[j][i] = grid[j-1][i] + grid[j][i-1]
        return grid[m-1][n-1]
                
obstacleGrid = [ [0,0,0], [0,1,0], [0,0,0]]
s = Solution()
print s.uniquePathsWithObstacles(obstacleGrid)     