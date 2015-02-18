#include <iostream>
#include <vector>
#include <Algorithm>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
    	string prefix;
       	if( strs.size() == 0)
       		return prefix;

       	prefix = strs[0];
       	//cout << prefix << endl;
       	for( int i = 1; i < strs.size(); i ++ )
       	{
       		int index = 0;
       		while( strs[i][index] == prefix[index++] );
       		prefix = prefix.substr(0,index-1);

       	}
       	return prefix;
    }
};

int main(int argc, char const *argv[])
{	
	Solution *s = new Solution();
	vector<string> vec;
	vec.push_back(string("abcd"));
	vec.push_back(string("abcde"));
  //vec.push_back(string("abc"));

	cout << s->longestCommonPrefix(vec);
	return 0;
}