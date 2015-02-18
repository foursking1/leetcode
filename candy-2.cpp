#include <iostream>
#include <vector>
#include <Algorithm>
#include <set>

using namespace std;


class Solution {
public:
    int candy(vector<int> &ratings) {
        int size = ratings.size();
        vector<int> candy(size, 0);

        int k = 1;
        for( int i = 1;i < ratings.size(); i++ ) {
            if( ratings[i] > ratings[i-1])
                candy[i] = max(k++, candy[i]);
            else {
                k = 1;
            }
        }

        k = 1;
        for( int i = ratings.size() - 2; i >= 0; i--) {
            if(ratings[i] > ratings[i + 1]) {
                candy[i] = max(k++, candy[i]);
            } else {
                k = 1;
            }
        }
        int ans = ratings.size();

        for( int i = 0 ; i < ratings.size(); i ++ ) ans += candy[i];

        return ans;

    }

};

int main(int argc, char const *argv[])
{	
	vector<int> vec = {2,2};


	return 0;
}