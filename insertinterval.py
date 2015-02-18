class Interval:
    def __init__(self, s=0, e=0):
        self.start = s
        self.end = e

class Solution:
    # @param intervals, a list of Interval
    # @return a list of Interval
    def insert(self, intervals, newInterval):
        res = []
        cur = Interval(0,0)
        intervals.append(newInterval)
        sortedInters = sorted(intervals, key = lambda interval:interval.start)
        
        for value in sortedInters:
            #top element
            if len(res) > 0:
                cur  = res[len(res)-1]
            if value.start > cur.end or len(res) == 0:
                res.append(value)
            else:
                start = cur.start
                end = max( value.end, cur.end)
                del res[len(res)-1]
                res.append(Interval(start,end))
                
        for value in res:
            print str(value.start)+','+str(value.end)
        return res 
            
intervals = [Interval(1,3)]
s = Solution()
s.merge(intervals)