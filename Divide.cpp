#include <iostream>
#include <vector>
#include <Algorithm>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        
        int res = 0;
        int flag = 1;
        if ( divisor == 0 || dividend == 0)
        	return 0;

        if( divisor == 1)
        	return dividend;
        if( divisor == -1)
        	return -dividend;
        if( dividend > divisor)
            return 0;


        if( ( dividend < 0 && divisor > 0 ) || (dividend > 0 && divisor < 0) )
        	flag = -1;

        dividend = abs(dividend);
        divisor = abs(divisor);
        int sub = divisor;
        int c = 1;
        int ret = 0;


        while( dividend >= divisor) {
            if( dividend >= sub) {
                dividend -= sub;
                ret += c;
                sub = (sub<<1);
                c = (c<<1);
            }
            else {
                sub = (sub >> 1);
                c = (c>>1);
            }
        }
        if( flag == -1)
            ret = -ret;
        return ret;
    }
};

int main(int argc, char const *argv[])
{	
	int dividend = -1010369383;
	int divisor = -2147483648;
    //cout << -divisor;
	Solution *s = new Solution();
	cout << s->divide(dividend,divisor);
	return 0;
}