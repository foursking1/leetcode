#include <iostream>
#include <vector>
#include <Algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        int min = 10000;
        int res = 0;

        for(vector<int>::const_iterator it = num.begin(); it != num.end(); it ++ )
        {
        	vector<int>::const_iterator front = it + 1;
        	vector<int>::const_iterator back = num.end() - 1;

        	while(front < back )
        	{
        		int const sum = *it + *front + *back;
        		if( abs(target - sum) < min )
        		{
        			min = abs(target - sum);
        			res = sum;
        		}

        		if( sum > target)
        			back --;

        		else if( sum < target)
        			front++;
        		else
        			return sum;
        	}

        }
        return res;
    }
};

int main(int argc, char const *argv[])
{	
	vector<int> vec = { 1, 1, 1, 1};
	Solution *s = new Solution();
	cout << s->threeSumClosest(vec, -100);
	return 0;
}