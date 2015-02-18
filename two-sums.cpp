#include <iostream>
#include <vector>
#include <Algorithm>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int n = numbers.size();
        map<int,int> findmap;
        map<int,int>::iterator it;
        vector<int> sol;

        for( int i = n - 1; i >=0 ; i--) {
            findmap.insert(pair<int,int>(numbers[i],i));
            it = findmap.find(target-numbers[i]);
            if( it!=findmap.end() && i < it->second)
            {
                sol.push_back(i+1);
                sol.push_back(it->second+1);
            }
        }
    }
};


int main(int argc, char const *argv[])
{    
    return 0;
}


