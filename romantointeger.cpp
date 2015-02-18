#include <iostream>
#include <vector>
#include <Algorithm>
#include <map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
    	int n = s.size();
    	int flag = 1;
    	map< char, int> map;
    	map['I'] = 1;
    	map['V'] = 5;
    	map['X'] = 10;
    	map['L'] = 50;
    	map['C'] = 100;
    	map['D'] = 500;
    	map['M'] = 1000;

    	int res = 0;

    	for(int i = 0; i < n; i++)
    	{
    		flag = 1;
    		if( i < n - 1)
    		{
    			if( map[s[i]] < map[s[i+1]])
    				flag = -1;
    		}
    		res = res + map[s[i]] * flag;
    	}
    	return res;
    }
    string intToRoman(int num) {
    	string res;
    	map< int, string> map;
    	vector<string> reverse;

    	map[1] = "I";
    	map[5] = 'V';
    	map[10] = 'X';
    	map[50] = 'L';
    	map[100] = 'C';
    	map[500] = 'D';
    	map[1000] = 'M';

    	
    	int ten = 1;

		while(num) {
			string tmp;
			int digit = num % 10;
			if( digit == 9)
				tmp = map[ten] + map[ten*10];
			else if( digit == 4)
				tmp = map[ten] + map[ten*5];
			else {
				if( digit >= 5) {
					digit -= 5;
					tmp = map[ten*5];
				}

				for( int i = 0; i < digit; i++)
				{
					tmp = tmp + map[ten];
				}
			}

			num = num / 10;
			ten = ten * 10;
			reverse.push_back(tmp);
			//res += tmp;
		}	
		for( int i = reverse.size() - 1; i >= 0; i-- )
		{
			res += reverse[i];
		}
		return res;

    }
};


int main(int argc, char const *argv[])
{	
	Solution *s = new Solution();
	cout << s->intToRoman(99);
	return 0;
}