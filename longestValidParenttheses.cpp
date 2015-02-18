#include <iostream>
#include <vector>
#include <Algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        if( n == 0)
        	return 0;
        vector<int> dp(n,0);



        for(int i = 0; i < n; i ++ )
        {
        	if( i == 0)
        		continue;

        	
        	int length = 0;
        	int stack = 0;
        	int last = 0;

			for( int j = i; j >= 0; j --){
				if( s[j] == ')') {
					stack ++;
					last ++;
				}
				else if( s[j] == '(' && stack > 1)
					stack --;

				else if( s[j] == '(' && stack == 1) {
					stack --;
					length += last * 2;
					last = 0;
				}

				else if( s[j] == '(' && stack < 1) 
					break;
					


			}   			

        	dp[i] = max(dp[i-1], length);
        	//cout << "i:" << i << "max:"<< dp[i] << endl;
        }
        return dp[n-1];
    }
};

int main(int argc, char const *argv[])
{	
	string s = "())";
	Solution *sol = new Solution();
	cout<< sol->longestValidParentheses(s);
	return 0;
}