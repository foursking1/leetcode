class Solution:
    # @param ratings, a list of integer
    # @return an integer
    def candy(self, ratings):
        candies = [1 for i in range(len(ratings))]
        for i in range(1, len(ratings)):
            if ratings[i] > ratings[i-1]:
                candies[i] = candies[i-1] + 1
        
        for i in reversed(range(1, len(ratings))):
            if ratings[i-1] > ratings[i] and candies[i-1] <= candies[i]:
                candies[i-1] = candies[i] + 1
        #print candies
        return reduce(lambda x,y: x + y , candies)
        
        
            
rat = [0.1,0.3,0.2,0.15,0.1]
s = Solution()
print s.candy(rat)