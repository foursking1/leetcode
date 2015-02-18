class Solution:
    # @param num, a list of integer
    # @return an integer
    def findMin(self, num):
    	left = 0
    	right = len(num) - 1
    	while left < right - 1:
    		middle = left + (right - left)/2
    		if num[middle] > num[right]:
    			left = middle;
    		else:
    			right = middle;

    	return num[left] if num[left] < num[right] else num[right]



a = [ 1, 2, 3]
b = [ 1 ,2, 0]

s = Solution()
print(s.findMin(b))

