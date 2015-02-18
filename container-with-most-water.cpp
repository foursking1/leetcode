#include <iostream>
#include <vector>
#include <Algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
    	int maxArea = 0;

        for( int i = 0; i < height.size(); i++)
        {
        	for( int j = i + 1; j < height.size(); j++)
        	{
        		int area = abs(height[j] - height[i]) * (j - i);
        		if ( area > maxArea)
        			maxArea = area; 
        	}
        }
        return maxArea;
    }

    int maxArea(vector<int> &height) {
    	int i = 0;
    	int j = height.size() - 1;
    	int maxArea = 0;

    	while(i < j) {
    	   	maxArea = max( maxArea, abs(height[j] - height[i]) * (j - i));

    	   	if( height[i] < height[j])
    	   		i++
    	   	else if( height[i] >= height[i])
    	   		j--;

    	}

    	return maxArea;
    }
};

int main(int argc, char const *argv[])
{	
	return 0;
}