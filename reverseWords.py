class Solution:
    # @param s, a string
    # @return a string
	def reverseWords(self, s): 
		res = " ".join([i for i in s.split(" ") if i != ""][::-1])
		return res


s = Solution();
str = "  the sky   is blue  "
print(s.reverseWords(str))