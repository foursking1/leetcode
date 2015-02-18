#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;


class Solution {
public:
    int evalRPN(vector<string> &tokens) {
		stack <string> stk;
		string lvalue;
		string rvalue;
		int result;
		
		for ( vector< string >::iterator it = tokens.begin() ; it != tokens.end() ; it ++ )
		{

			if ( *it == "+" )
			{
				rvalue = stk.top();
				stk.pop();
				lvalue = stk.top();
				stk.pop();
				result = ( stoi(lvalue) )  + ( stoi(rvalue) );
				
				stk.push(to_string(result));
			}
			else if ( *it == "-" )
			{
				rvalue = stk.top();
				stk.pop();
				lvalue = stk.top();
				stk.pop();
				result = ( stoi(lvalue) )  - ( stoi(rvalue) );
				
				stk.push(to_string(result));
			}
			else if ( *it == "*" )
			{
				rvalue = stk.top();
				stk.pop();
				lvalue = stk.top();
				stk.pop();
				result = ( stoi(lvalue) )  * ( stoi(rvalue) );
				
				stk.push(to_string(result));
			}
			else if ( *it == "/" )
			{
				rvalue = stk.top();
				stk.pop();
				lvalue = stk.top();
				stk.pop();
				result = ( stoi(lvalue) )  / ( stoi(rvalue) );
				
				stk.push(to_string(result));
			}
			else
			{
				stk.push(*it);
			}
			
		}
		
		result = stoi( stk.top() );
		stk.pop();
		return result;

    }
};



int main()
{
	vector< string > test1 = {"2", "1", "+", "3", "*"};
	vector< string > test2 = {"4", "13", "5", "/", "+"};
	vector< string > test3 = { "3","-4","+" };
	
	Solution s;
	cout << s.evalRPN(test3) << endl;	 
	return 0;
}