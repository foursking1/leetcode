class Solution:
    # @param matrix, a list of lists of integers
    # RETURN NOTHING, MODIFY matrix IN PLACE.
    def setZeroes(self, matrix):
        row = len(matrix)
        column = len(matrix[0])
                
        rowhaszero = 0
        columnhaszero = 0
        
        
        for i in range(0,row):
            for j in range(0,column):
                if matrix[i][j] == 0:
                    if i == 0 and j == 0:
                        rowhaszero = 1
                        columnhaszero = 1
                    elif i == 0 and j != 0:
                        columnhaszero = 1
                    elif i != 0 and j == 0:
                        rowhaszero = 1
                    else:   
                        matrix[0][j] = 0
                        matrix[i][0] = 0
                    
        
        for i in range(1,row):
            if matrix[i][0] == 0:
                for j in range(column):
                    matrix[i][j] = 0         

        for j in range(1,column):
            if matrix[0][j] == 0:
                for i in range(row):
                    matrix[i][j] = 0  
                    
        
        if rowhaszero:
            for i in range(row):
                matrix[i][0] = 0
                
        if columnhaszero:
            for j in range(column):
                matrix[0][j] = 0
                    
s = Solution()
num = [[1,1,1],[0,1,2]]
s.setZeroes(num)
print num