class Solution:
    # @param digits, a list of integer digits
    # @return a list of integer digits
    def plusOne(self, digits):
        for i in range(len(digits)-1, -1, -1):
            digits[i] = (digits[i] + 1) % 10
            if digits[i]:
                break;
        else:
            digits.insert(0,1)
        return digits   