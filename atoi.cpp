#include <iostream>
#include <vector>
#include <Algorithm>
#include <cstdint>
using namespace std;


class Solution {
public:
    int atoi(const char *str) {
    	//cout << *str << endl;
        const char *ptr = str;
        
        int res = 0;
 		enum state {
 			sign,
 			num,
 			character
 		};
 		int flag = 1;

 		state s = sign;

        for( ; *ptr != NULL ; ptr ++) {
        	char tmp = *ptr;
    		if( s == sign) {
    			if( tmp == ' ' || tmp == '0')
    			{
    				s = sign;
    			}
    			else if( tmp == '+') {
    				flag = 1;
    				s = num;
    			}      				
    			else if( tmp == '-') {
    				flag = -1;
    				s = num;	
    			}      				
    			else if( tmp >= '0' && tmp <= '9'){
    				res = res * 10 + (tmp-'0');
    				s = num;
    			}
    			else 
    				return 0;
    		}
    		else if( s == num) {
    			if( tmp >= '0' && tmp <= '9') {
    				if( res > INT_MAX / 10 || (res == INT_MAX / 10 &&  tmp - '0' > 7 )) 
    				{
    					if( flag == 1) return INT_MAX;
    					else return INT_MIN;
    				}

    				res = res * 10 + (tmp-'0');


    			} 
    			else 
    				break;

    		}
        	
        }

        res = res * flag;

        return res;


    }
};

int main(int argc, char const *argv[])
{	
	const char *num = "  010";
	Solution *s = new Solution();
	cout << s->atoi(num);
	return 0;
}