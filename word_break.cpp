#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std; 

class Solution {
public:
	bool wordBreak(string s, unordered_set<string> &dict) {
		int n = s.size();
    	vector<bool> dp(n+1,false);
		dp[0] = true;
	
		for (int i = 1 ; i <= n ; i++)
    	{
			if(dp[i-1])
			{
				int index = i-1;
				for (int j = index ; j < n ; j++)
				{
					string cur = s.substr(index , j - index + 1);
					if (dict.count(cur) > 0)
						dp[i+1] = true;
				}
			}
		}
		
		return dp[n];
	}
	
}solution;



bool wordBreak(string s, unordered_set<string> &dict) {
        if(dict.size()==0) return false;

        vector<bool> dp(s.size()+1,false);
        dp[0]=true;

        for(int i=1;i<=s.size();i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(dp[j])
                {
                    string word = s.substr(j,i-j);
                    if(dict.count(word)>0))
                    {
                        dp[i]=true;
                        break; //next i
                    }
                }
            }
        }

        return dp[s.size()];
    }

int main()
{
	string s = "abc";
	unordered_set<string> dict = { "a" , "b" };
	cout << solution.wordBreak(s , dict) << endl;
	//cout << "hellp" <<endl;
	
}