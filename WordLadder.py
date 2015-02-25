class Solution:
    # @param start, a string
    # @param end, a string
    # @param dict, a set of string
    # @return an integer
    def ladderLength(self, start, end, dict):
        current = [start]
        lenn = len(dict)
        step = 1
        
        while len(current):
            #print step
            #print current
            #print dict
            next = []
            nextdict = set()
            
            for word in current:
                if self.onestep(word, end):
                    #print word,end
                    return step + 1
                for tar in dict:
                    if self.onestep(word, tar):
                        next.append(tar)
                    else:
                        nextdict.add(tar)              
            step += 1
            current = next
            dict = nextdict
            if step > lenn:
                return 0
        return 0
                
    def onestep(self, s, t):
        step = 0
        for i in range(len(s)):
            if s[i] is not t[i]:
                step += 1
        
        if step == 1:
            return True
        else:
            return False
            
    def ladderLength2(self, start, end, dict):
        distance, current, visited = 0, [start], set([start])
        dict.add(end)
        while current:
            next = []
            for word in current:
                if word == end:
                    return distance + 1
                for i in range(len(word)):
                    for j in 'abcdefghijklmnopqrstuvwxyz':
                        candidate = word[:i] + j + word[i + 1:]
                        if candidate not in visited and candidate in dict:
                            next.append(candidate)
                            visited.add(candidate)
            distance += 1
            current = next
        return 0      

            
s = Solution()
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
#print "ssss"
print s.ladderLength(start, end, dict)
            
                
                              