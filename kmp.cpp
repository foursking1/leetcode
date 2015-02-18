#include <iostream>
#include <vector>
#include <Algorithm>

using namespace std;

void calnext(char *s, int *next) 
{
	int len = strlen(s);
	next[0] = -1;
	int j = -1;
	for( int i = 1; i < len; i ++ ){
		while( j >= 0 && s[i] != s[j+1])
			j = next[j];

		if( s[i] == s[j+1])
			j ++;

		next[i] = j;
	}
}


int main(int argc, char const *argv[])
{	
	char *s = "abcdbce";
	int *next = new int[7];
	calnext(s,next);
	for(int i = 0; i < strlen(s); i ++)
		cout << next[i] << endl;
	return 0;
}
