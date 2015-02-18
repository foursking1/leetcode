class Solution:
    # @param board, a list of lists of 1 length string
    # @param word, a string
    # @return a boolean
    def exist(self, board, word):
        self.lenm = len(board)
        self.lenn = len(board[0])
        for i in range(self.lenm):
            for j in range(self.lenn):
                if board[i][j] == word[0]:
                    t, board[i][j] = board[i][j], ' '
                    if self.dfs(board, word, i, j, 1):
                        return True
                    board[i][j] = t
        return False
        
    def dfs(self, board, word, x, y, k):
        dx, dy = [1,-1,0,0],[0,0,1,-1]
        if k == len(word):
            return True
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            if nx >= 0 and nx < self.lenm  and ny >= 0 and ny < self.lenn and board[nx][ny] == word[k]:
                t, board[nx][ny] = board[nx][ny], ' '
                if self.dfs(board, word, nx, ny, k + 1):
                    return True
                board[nx][ny] = t
        return False
        
s = Solution()
s.exist()
            

            
            
            