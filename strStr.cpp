#include <iostream>
#include <vector>
#include <Algorithm>

using namespace std;

class Solution {
public:
    int strStr(char *haystack, char *needle) {
        if( haystack == NULL || needle == NULL)
        	return -1;

        char *p = haystack;
        char *reg = needle;
        int pos = 0;

        while( *haystack != '\0'  )
        {
        	while( *p == *reg && (*p != '\0'))
        	{
        		p++;
        		reg++;
        	}
        	//cout << *haystack << endl;
        	//cout << *reg << endl;
        	if( *reg == '\0')
        	{
        		return pos;
        	}
        	else
        	{
        		haystack ++;
        		pos += 1;
        		reg = needle;
        		p = haystack;
        	}
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{	
	char *p = "baa";
	char *reg = "baa";
	Solution *s = new Solution();
	cout << s->strStr(p,reg);
	return 0;
}