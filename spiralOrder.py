class Solution:
    # @param matrix, a list of lists of integers
    # @return a list of integers
    def spiralOrder(self, matrix):
        res = []
        if (len(matrix)) == 0:
            return res
        n = len(matrix) - 1
        m = len(matrix[0]) - 1
        left = 0
        right = 0
        while n >= 0 and m  >= 0:
            #start element
            res.append(matrix[left][right])
            
            #
            for i in range(m):
                right = right + 1
                res.append(matrix[left][right])
               
                        
            for i in range(n):
                left = left + 1
                res.append(matrix[left][right])
                
            for i in range(m):
                if n > 0:
                    right = right - 1
                    res.append(matrix[left][right])
                
            for i in range(n-1):
                if m > 0:
                    left = left - 1
                    res.append(matrix[left][right])
           
            right += 1 
            n = n - 2
            m = m - 2
         
        return res   
            
s = Solution()
mat = [[7],[9],[6]]
print s.spiralOrder(mat)    