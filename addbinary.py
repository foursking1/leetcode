class Solution:
    # @param a, a string
    # @param b, a string
    # @return a string
    def addBinary(self, a, b):
        a = [ord(c) - ord('0') for c in a][::-1]
        b = [ord(c) - ord('0') for c in b][::-1]
    
        if (len(a) < len(b)):
            a,b = b,a
        flag = 0
        
        for i in range(len(a)):
            if (i< len(b)):
                a[i] += b[i]
            a[i] += flag
            flag = a[i] // 2
            a[i] %= 2
        if flag:
            a.append(1)
        return ''.join([chr(c+ord('0')) for c in a][::-1])
            
            
            
s = Solution()
s.addBinary('11','1')