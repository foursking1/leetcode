//reading problem carefully
//thinking then writing

#include <iostream>
#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
		const string compare = " " ;
		vector < string > vec ; 
		
		int flag , flag2;
		size_t first_pos = 0;
		size_t pos = 0;
		flag = 1;
		flag2 = 1;
		
		for ( size_t i = 0 ; i < s.size() ; i ++ )
		{
			if ( s[i] == ' ' )
			{
				if ( pos - first_pos != 0 && flag == 0)
				{
					vec.push_back( s.substr ( first_pos , pos - first_pos ));
					flag = 1;
				}
				
				continue;
			}
			
			
			if ( flag )
			{
				first_pos = i;
				pos = first_pos;
				flag = 0;
			}
			//cout << i << endl;
			pos ++;
			
			if ( i == s.size() - 1 && s[i] != ' ')
			{
				vec.push_back( s.substr ( first_pos , pos - first_pos ));
			}
				
		}
		
		int first = 1;
		s.clear();
		
		for ( vector < string > :: reverse_iterator it = vec.rbegin() ; it != vec.rend() ; it ++)
		{
			if ( first )
			{
				s += *it;
				first = 0;
			}
			else
			{
				s = s + " " + *it;
			}
			
			//cout << *it << endl;
		}
        
	//	cout << s << endl;

    }
};



int main()
{
	string s = "s";
	Solution solut;
	solut.reverseWords ( s );
	return 0;
}