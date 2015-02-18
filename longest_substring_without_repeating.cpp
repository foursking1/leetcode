#include <iostream>
#include <map>
#include <vector>
#include <Algorithm>

using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		int hash[28] = { 0 };
		int length = 0;
		int max_length = 0;
		int index = 0;
		
		while( index < s.size())
		{
			if( hash[ s[index] - 'a' ] )  // if it is in hash table , existed
			{
				//clear the hash table
				for ( int j = 0 ; j < 28 ; j ++)
					hash[j] = 0;
					
					
				if (length >= max_length)
					max_length = length;
					
				length = 0;	
				
				//backtracking	
				for ( int k = index-1 ; k>=0 ; k --)
				{
					if ( s[k] == s[index])
					{
						index = k + 1;
						break ;
					}
				}	
	
				//cout << " one: " << index << endl ;
			
			}
			else
			{

				length ++ ;
				hash[ s[index] - 'a' ] = 1;
				index ++ ;
				//cout << " two: "<<index << endl;
				
			}
		}
		
		if (length > max_length)
			max_length = length;
		return max_length;
        
    }
	
	int lengthOfLongestSubstring2(string s) {

		int n = s.size();
		map<char,int> findmap;
		vector<int> dp(n, 0);
		dp[0] = 1;

		for( int i = 1; i < n; i++ )
		{
			int maxValue = 0;
			for( int j = i; j >= 0; j-- ) {
				if(findmap.count(s[j]) != 0) {
					findmap.clear();
					break;
				} else {
					findmap[s[j]] = 1;
					maxValue ++;
				}
			}

			dp[i] = max(dp[i-1], maxValue);
		}

		return dp[n-1];

	}

	int lengthOfLongestSubstring3(string s) {

		int n = s.size();
		map<char,int> findmap;

		if( n == 0 ) return 0;

		int max = 1;
		int d = 1;
		findmap[s[0]] = 0;

		for( int i = 1; i < n; i++ )
		{
			if( findmap.count(s[i]) == 0 || findmap[s[i]] < i-d ) 
				d += 1;
			else 
				//important
				d = i - findmap[s[i]];

			findmap[s[i]] = i;
			if( d > max)
				max = d;
		}

		return max;

	}


	
}solution;


int main()
{
	string s = "qopubjguxhxdipfzwswybgfylqvjzhar";
	cout << solution.lengthOfLongestSubstring3(s) << endl;
}