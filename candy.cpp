#include <iostream>
#include <vector>
#include <Algorithm>

using namespace std;


class Solution {
public:
    int candy(vector<int> &ratings) {

        int flag = 1;
        int left,middle,right,
        vector<int> ret;
        int sum = 0;
        while(flag) {
        	flag = 0;
            for( int i = 0; i < ratings.size(); i++){
            	if(i == 0) {
            		left = 0;
            		middle = ratings[0];
            		right = ratings[1];
            	} else if( i == ratings.size() - 1) {
            		left = ratings[i-1];
            		middle = ratings[i];
            		right = 0;
            	} else {
            		left = ratings[i-1];
            		middle = ratings[i];
            		right = ratings[i+1];
            	}

            	ret = process(left, middle, right);
            	ratings[i] -= ret;
            	if(ret) {
            		flag = 1;
            	}
            }

        }

        for(auto i:ratings) {
        	sum += i;
        }
        return sum;
    }

    int process(int left, int middle, int right) {
    	vector<int> ret = {0,0,0};


    	vector<int> vec = {left, middle, right};
    	sort(vec.begin(), vec.end());

    	//min
    	if( middle == vec[0]) {
    		ret[1] = middle - 1;
    	}

    	if( middle == vec[1]) {
    		ret[1] = middle - vec[0] - 1;
    	}

    	if( middle == vec[2]) {
    		ret = middle - vec[1] - 1;
    	}

    	return ret;
    }

};

int main(int argc, char const *argv[])
{	
	vector<int> vec = {2,2};
	Solution *s = new Solution();
	s->candy(vec);

	return 0;
}