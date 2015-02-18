class Solution:
    # @return a string
    def minWindow(self, S, T):
        d, dt = {}, dict.fromkeys(T,0)
        for c in T:
            d[c] = d.get(c,0) + 1
        pl, pr, count = 0, 0, 0
        ans = ""
        while pr < len(S):
            if S[pr] in dt:
                if dt[S[pr]] < d[S[pr]]:
                    count += 1
                dt[S[pr]] += 1;
            
            if count == len(T):
                while pl < pr:
                    if S[pl] in dt:
                        if dt[S[pl]] == d[S[pl]]:
                            break;
                        dt[S[pl]] -= 1;
                    pl += 1
                if ans == "" or pr - pl < len(ans):
                    ans = S[pl:pr+1]
                dt[S[pl]] -=1
                pl += 1
                count -= 1
            pr += 1
        return ans
        
s = Solution()
print s.minWindow('abcsddascb','abc')
                
                 
        
                
            