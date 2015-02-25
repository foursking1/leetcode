class Solution:
    # @param s, a string
    # @param dict, a set of string
    # @return a list of strings
    def wordBreak(self, s, dict):
        possible = []
        for i in range(len(s)):
            
            if s[:i+1] in dict:
                possible.append(True)
            else:
                found = False
                for j in range(i):                  
                    if possible[j] == True and s[j+1:i+1] in dict:                        
                        found = True
                        break
                possible.append(found)
        return possible[len(s)-1]
        
    def backtrack():
        pass
                
str = "catsanddog"
dict = ["cat", "cats", "and", "sand", "dog"]
s = Solution()
print s.wordBreak(str, dict)