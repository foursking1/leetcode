/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
*/

#include <iostream>
#include <vector>

using namespace std;
	
class Solution {
public:
    vector<string> generateParenthesis(int n) {
		vector<string> vec ;
		
		generate(n , n , "" ,  vec);
		
		return vec;
	}
	
	void generate( int leftnum , int rightnum , string s , vector<string> &vec)
	{
		if ( leftnum == 0 && rightnum == 0)
		{
			vec.push_back(s);
		}
		if ( leftnum > 0)
		{
			generate( leftnum - 1 , rightnum , s+'(' , vec);
		}	
		if ( rightnum > 0 && leftnum < rightnum)
		{
			generate( leftnum , rightnum - 1 , s+')' , vec);
		}
	}
	
}solution;

int main()
{
	vector<string>  res = solution.generateParenthesis(3);
	
	for ( int i = 0 ; i < res.size() ; i++)
		cout << res[i] << " " ;
	cout << endl;
}	