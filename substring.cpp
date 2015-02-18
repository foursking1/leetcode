#include <iostream>
#include <vector>
#include <Algorithm>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        unordered_map< string, int> map;
        for( int i = 0; i < L.size(); i++) {
        	if( map.count(L[i]) > 0)
                map[L[i]] += 1;
            else
                map[L[i]] = 0;
        }
        vector<int> ret;
        if( L.size() == 0)
        	return ret;

        int size = L[0].size();
        int len = S.size();
    	int plen = L.size();
    	int i = 0;
        int j = i;
    	//int pos = 0;
    	while( i < len - size * plen + 1 ) {
    		cout << "i:" << i << endl; 
    		unordered_map< string, int> findmap = map;
    		while( !findmap.empty()){
                //cout << "here" << endl;
    			string str = S.substr(j,size);
    			if( findmap.count(str) > 0) 
    			{
    				j += size;
                    if( findmap[str] > 0 )
                        findmap[str] --;
                    else
    				    findmap.erase(str);
				} 
				else 
				{
					break;
				}
    		}
            cout << "j:" << j << endl;
            if( (j - i) == size * plen) 
    			ret.push_back(i);
            //j = i;
            i += 1;
            j = i;

    	}
        return ret;
    }
};


int main(int argc, char const *argv[])
{	
	string S = "a";
	vector<string> vec;
	vec.push_back(string("a"));
	// vec.push_back(string("barr"));
 //    vec.push_back(string("ding"));
 //    vec.push_back(string("wing"));
 //    vec.push_back(string("wing"));
	Solution *s = new Solution();
	vector<int> res;
	res = s->findSubstring(S,vec);
	for( int i = 0; i < res.size(); i ++)
	{
		cout << res[i] << endl;
	}
	return 0;
}