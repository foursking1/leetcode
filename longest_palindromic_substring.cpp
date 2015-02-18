#include <iostream>
#include <vector>
#include <Algorithm>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int max = 0;
        int length = 0;
        int n = s.size();
        //string res = "";
        int lindex;
        int rindex;
        string res;

        if( n == 1) {
        	return s;
        }

        for( int i = 1; i < n; i ++)
        {
        	if(s[i] == s[i-1])
        	{
        		lindex = i-1;
        		rindex = i;
        		length = 0;
        		while( s[lindex] == s[rindex]) {
        			length += 2;
        			lindex --;
        			rindex ++;

        			if( lindex < 0 || rindex >= n) {
        				break;
        			}

        		}
        		if( length > max) {
        			res = s.substr( lindex + 1, rindex - lindex -1);
        			max = length;
        		}
        	}
        }

        return res;


    }

    string longestPalindrome2(string s) {
        int max = 0;
        int length = 0;
        int n = s.size();
        //string res = "";
        int lindex;
        int rindex;
        string res;

        if( n == 1) {
        	return s;
        }

        for( int i = 1; i < n; i ++)
        {
        	if(s[i] == s[i-1])
        	{
        		lindex = i-1;
        		rindex = i;
        		length = 0;
        		while( s[lindex] == s[rindex]) {
        			length += 2;
        			lindex --;
        			rindex ++;

        			if( lindex < 0 || rindex >= n) {
        				break;
        			}

        		}
        		if( length > max) {
        			res = s.substr( lindex + 1, rindex - lindex -1);
        			max = length;
        		}
        	}
        	if( s[i-1] == s[i+1] && i < n - 1) 
        	{
        		lindex = i-1;
        		rindex = i+1;
        		length = 1;
        		while( s[lindex] == s[rindex]) {
        			length += 2;
        			lindex --;
        			rindex ++;

        			if( lindex < 0 || rindex >= n) {
        				break;
        			}

        		}
        		if( length > max) {
        			res = s.substr( lindex + 1, rindex - lindex -1);
        			max = length;
        		}        		
        	}
        }

        return res;


    }

    string longestPalindrome3(string s) {
    	int n = s.size();

    	if( n == 1)
    		return s;

    	int ss = 0;
    	int tt = 0;
    	int max = 0;
    	int dp[n][n];
    	memset(dp, 0, sizeof(dp));

    	for(int i = 0; i < n; i ++){
    		for(int j = 0; j < n; j ++)
    			if( i >= j) {
    				dp[i][j] = 1;
    			}
    	}

    	for( int i = 1; i < n; i ++ ) {
    		for( int j = i -1; j >= 0; j--) {
    			if( s[i] == s[j]) 
    			{
    				dp[j][i] = dp[j+1][i-1];

    				if( dp[j][i] == 1 && i - j + 1) {
    					if( i - j + 1 > max) {
	    					max = i - j + 1;
	    					ss = j;
	    					tt = i;
	    				}
    				}
    			}
    			else
    				dp[j][i] = 0;
    		}
    	}

    	return s.substr(ss,max);
    }
};


int main(int argc, char const *argv[])
{	
	Solution *s = new Solution();
	string a = "aaasabaaa";
	cout << s->longestPalindrome3(a);
	return 0;
}