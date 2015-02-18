#include <iostream>
#include <vector>
#include <Algorithm>
#include <stack>
#include <string>
#include <map>

using namespace std;
//[]{}
//[{}]

class Solution {
public:
    bool isValid(string s) {
    	map<char, int> map;
    	map['['] = 0;
    	map[']'] = 0;
    	map['('] = 1;
    	map[')'] = 1;
    	map['{'] = 2;
    	map['}'] = 2;

    	if( s.size() == 0)
    		return false;

        stack<char> stack;
        for( int i = 0; i < s.size(); i ++ ) {

        	//cout << map[s[i]] << endl;
        	//char match = stack.
        	if( !stack.empty() && stack.top() != s[i] && map[stack.top()] == map[s[i]] )
        		stack.pop();
        	else
        		stack.push(s[i]);
        }

        if( stack.size() == 0)
        	return true;
        else
        	return false;

    }
};

int main(int argc, char const *argv[])
{	
	string s = "((";
	Solution *sol = new Solution();
	cout << sol->isValid(s);
	return 0;
}