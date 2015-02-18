#include <iostream>
#include <vector>
#include <Algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &num) {
    	if( num.size() == 0 || num.size() == 1)
    		return ;



    	int lastelm = num.back();

        for( vector<int>::iterator it = num.end(); it > num.begin(); it-- ) {
        	if( *(it-1) < *it )
        	{
        		//save the position
        		//cout << "sss" << endl;
        		vector<int>::iterator pos = it - 1;
        		vector<int>::iterator iter = it;
        		while( *iter > *pos && iter != num.end())
        			iter ++;

        		//point to the prev potision
        		iter --;
        		
        		//change the value;
        		int tmp = *pos;
        		*pos = *iter;
        		*iter = tmp;

        		
        		//sort the rest
        		if( ++ pos != num.end())
        		sort(pos, num.end());

        		//find the postion
        		
        		return;
        	}
        }

    	sort(num.begin(), num.end());

    	return;
    }
};

int main(int argc, char const *argv[])
{
	vector<int> vec = {1,2,3};

	Solution *s = new Solution();
	s->nextPermutation(vec);
	    	for(int i = 0; i < vec.size(); i ++)
    		cout << vec[i] << endl;

	return 0;
}