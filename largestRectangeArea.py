class Solution:
    # @param height, a list of integer
    # @return an integer
    def largestRectangleArea(self, height):
        ans, lenh, stk = 0, len(height), []
        for i in range(lenh + 1):
            while len(stk) and (i == lenh or height[stk[-1]] >= height[i]):
                top = stk.pop()
                if len(stk) == 0:
                    ans = max(ans, height[top] * i)
                else:
                    ans = max(ans, height[top] * (i - stk[-1] - 1))
            stk.append(i)
        return ans