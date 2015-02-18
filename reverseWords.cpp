#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
    	enum STATE { 
    	    InWord,
    		InSpace
    	};

    	STATE state = InSpace;
    	vector<string> vec;
    	string word = "";

        for(int i = 0; i < s.size(); i ++)
        {
        	switch(state){
        		case(InSpace): 
        			if(s[i] != ' ' ) {
        				word.push_back(s[i]);
        				state = InWord;
        			}
        			break;
        		case(InWord):
        			if(s[i] == ' ') {
        				vec.push_back(word);
        				word.clear();
        				state = InSpace;
        			} else {
        				word.push_back(s[i]);
        			}
        			break;
        		default:
        			break;

        	}


        }
        if (word.size())
        	vec.push_back(word);

        int first = 1;
        s.clear();
        for(vector<string>::reverse_iterator it = vec.rbegin(); it < vec.rend(); it++) {
        	if(first) {
        		//cout << *it ;
        		s += *it;
        		first = 0;
        	}
        	else
        		//cout << " " << *it;
        		s += (' ' + *it);
        }
 
        	

        
    }
};


int main(int argc, char const *argv[])
{
	
	Solution s;
	string str = "a sssss sss ss    ";
	s.reverseWords(str);
	cout << str << endl;
	return 0;
}