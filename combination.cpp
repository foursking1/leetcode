#include <iostream>
#include <vector>
#include <Algorithm>
#include <stack>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
    	vector<string> res;
    	stack<string> stack;
        map< int, string > map;
        map[2] = "abc";
        map[3] = "def";
        map[4] = "ghi";
        map[5] = "jkl";
        map[6] = "mno";
        map[7] = "pqrs";
        map[8] = "tuv";
        map[9] = "wxyz";

        //a b c
        //ad ae af
        //bd be bf
        //cd ce cf

        for(int i = 0; i < digits.size(); i ++)
        {
        	int num = digits[i] - '0';
        	for(int j = 0; j < map[num].size(); j ++) {

        		}
        	}
        }
    }
};

int main(int argc, char const *argv[])
{	
	return 0;
}