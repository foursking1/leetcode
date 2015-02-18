class Solution:
    # @param matrix, a list of lists of integers
    # @return a list of lists of integers
    def rotate(self, matrix):
        n = len(matrix[0])
        if n % 2 == 0:
            xlen = n / 2 - 1
            ylen = n / 2 - 1
        else:
            xlen = n / 2
            ylen = n / 2 - 1
            
        for i in range(0, xlen+1):
            for j in range(0, ylen+1):
                phase1 = matrix[i][j]
                phase2 = matrix[j][n-1-i]
                phase3 = matrix[n-1-i][n-1-j]
                phase4 = matrix[n-1-j][i]
                
                #rotate
                matrix[i][j] = phase4
                matrix[j][n-1-i] = phase1
                matrix[n-1-i][n-1-j] = phase2
                matrix[n-1-j][i] = phase3
        return matrix

matrix = [[1,2,1],[1,2,1],[2,3,2]]                
s = Solution()
print s.rotate(matrix)
                