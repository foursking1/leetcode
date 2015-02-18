class Solution:
    # @param board, a 9x9 2D array
    # @return a boolean
    def isValidSudoku(self, board):
        if board == None:
            return False
            
        cols = [ {} for i in range(9)]
        rows = [ {} for i in range(9)]
        cells = [ {} for i in range(9)]
        
        for i in range(len(board)):
            for j in range(len(board[0])):
                
                if board[i][j] != ".":
                    key = board[i][j]
                    index = (i/3) * 3 + j/3
                    # the ith row 
                    if rows[i].get(key) or cols[j].get(key) or cells[index].get(key):
                        return False
                    else:
                        rows[i][key] = 1
                        cols[j][key] = 1
                        cells[index][key] = 1
        return True
                        
