class Solution:
    # @param matrix, a list of lists of integers
    # @param target, an integer
    # @return a boolean
    def searchMatrix(self, matrix, target):
                
        if len(matrix) == 0:
            return 
        lenn, lenm = len(matrix), len(matrix[0])
        
        left = 0
        right = lenn * lenm - 1
        
        while left <= right:
            #print left,right
             
            mid = (left + right) // 2
            i = mid // lenm
            j = mid % lenm
            
            if matrix[i][j] == target:
                return True
            elif matrix[i][j] < target:
                left = mid + 1
            else:
                right = mid - 1
         
               
        return False
        
s = Solution()  
matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,50]]
target = 1
print s.searchMatrix(matrix, target)
        
            