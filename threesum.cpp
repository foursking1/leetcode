#include <iostream>
#include <vector>
#include <Algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum2(vector<int> &num, int k) {
       	vector<vector<int> > ret;
       	unordered_map<int, int > map;
       	sort(num.begin(), num.end());
       	for( int i = 0; i < num.size(); i ++ )
       	{
       		map[num[i]] = i;
       	}
       	for( int  i = 0; i < num.size(); i ++) {
       		for( int j = i + 1; j < num.size(); j ++ )
       		{
       			int key = k - num[i] - num[j];
       			if( map.count(key)) {
       				// for( auto value : map[key])
       				// {
       				    int value = map[key];
       					int lasti = 0;
       					int lastj = 0;
       					if( ret.size() )
       					{
       						lasti = ret.back()[0];
       						lastj = ret.back()[1];
       					}
       					if( value > j && !(lasti == num[i] && lastj == num[j]) ) {
       						//cout << i << "," << j << "," << value << endl;
       						//cout << num[i] << "," << num[j] << "," << key << endl;
       						vector<int> tmp = { num[i], num[j], key};
       						ret.push_back(tmp);
       					}
       				// }
       			}
       		}
       	}
       	return ret;
    }

    vector<vector<int> > threeSum(vector<int> &num) {
    	return threeSum2(num, 0);
    }

vector<vector<int> > three_sum(vector<int> &num) 
{
    vector<vector<int> > ret;
    
    if (num.size() == 0) return ret;
    
    sort(num.begin(), num.end());
    
    for (vector<int>::const_iterator it = num.begin();
        it != num.end();
        ++it)
    {
        // Dedup
        if (it != num.begin() && *it == *(it - 1))
        {
            continue;
        }
        
        // Dedup, front = it + 1
        vector<int>::const_iterator front = it + 1;
        vector<int>::const_iterator back = num.end() - 1;
        
        while (front < back)
        {
            const int sum = *it + *front + *back;
            
            if (sum > 0)
            {
                --back;
            }
            else if (sum < 0)
            {
                ++front;
            }
            // Dedup
            else if (front != it + 1 && *front == *(front - 1))
            {
                ++front;
            }
            // Dedup
            else if (back != num.end() - 1 && *back == *(back + 1))
            {
                --back;
            }
            else
            {
                vector<int> result;
                
                // Already sorted.
                result.push_back(*it);
                result.push_back(*front);
                result.push_back(*back);
                
                ret.push_back(result);
                
                ++front;
                --back;
            }
        }
    }
    
    return ret;
}
};

int main(int argc, char const *argv[])
{	
	vector<int> vec = { -1, 0, 1, 2, -1, -4};
	Solution *s = new Solution();
	s->threeSum2(vec, 0);

	return 0;
}