#include <iostream>
#include <vector>
#include <Algorithm>
#include <cstdint>

using namespace std;

//input is 10000

class Solution {
public:
	int reverse(int x) {
		long int ret = 0;
		long int num = x;
		
		if( x > 1000000000 && ( x % 10 > 3))
			return 0;
		
		while(num)
		{
			//num = num / 10;
			ret = (ret + num%10) *10;
			num = num / 10;
		}
		ret = ret/10;
		
		if( ret > INT32_MAX || ret < INT32_MIN)
			return 0;


		return ret;
	}
};

int main(int argc, char const *argv[])
{	
	Solution *s = new Solution();
	int a = 214748368;
	cout << s->reverse(a);
	return 0;
}