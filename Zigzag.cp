#include <iostream>
#include <vector>
#include <Algorithm>
#include <string>

using namespace std;

/*
1 5 9  
2468
3 7
*/
class Solution {
public:
	string convert(string s, int nRows) {
		int n = s.size();
		//int size = nRows;
		int curRows = 0;
		int dir = 1;
		string dummy = "";
		vector<string> vec;

		string res;
		for( int i = 0; i < nRows; i++ )
		{
			vec.push_back(dummy);
		}
		for( int i = 0; i < n; i ++ ){
			vec[curRows].push_back(s[i]);
			curRows += dir;
			if(curRows == 0)
				dir = 1;
			else if(curRows == nRows - 1)
				dir = -1;

		}

		for( int i = 0; i < nRows; i++) {
			res += vec[i];
		}

		return res;

	}
	string convert2(string s, int nRows) {
	    if(nRows==1)
	        return s;

	    int y=0;
	    bool flag= true;
	    string sArray[nRows];
	    for(int i=0;i<nRows;i++)
	        sArray[i]="";

	    for(int i=0;i<s.length();i++){

	        sArray[y]+=s[i];

	        if(y==0){
	            flag=true;
	        }
	        if(y==nRows-1){
	            flag=false;
	        }

	        if(flag==true){
	            y++;
	        }else{
	            y--;
	        }


	    }

	    string ret="";

	    for(int i=0;i<nRows;i++){
	        ret+=sArray[i];
	    }

	    return ret;

	}

};

int main(int argc, char const *argv[])
{	
	Solution *s = new Solution();
	cout<< s->convert("AB",2);
	return 0;
}