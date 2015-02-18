#include <iostream>
using namespace std;

enum STATE { Space, Char};

int lengthOfLastWord(const char *s) {
    int length = 0;
	STATE state = Space;
    while( *s != '\0' )
    {
        if( *s == ' ')
		{
			if( state == Space)
			{
				s ++ ;
			}
			else
			{	
				state = Space;		
				s ++ ;
			}	
		}
		else
		{
			if ( state == Space)
			{
				state = Char;
				s ++ ;
				length = 1;
			}
			else
			{
				s ++ ;
				length ++;
			}
		}
    }
	return length;
}

int main()
{
	const char *s = "a ads";
	cout << lengthOfLastWord(s)<< endl;
}