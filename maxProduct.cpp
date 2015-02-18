#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


#consider the sign, and there is no zero


class Solution {
public:
    int maxProduct(int A[], int n) {
 		int r = A[0];
 		int imax = r;
 		int imin = r;

    	for(int i = 1; i < n; i++) {
    		if (A[i] < 0)
    			swap(imax,imin);
    		imax = max(A[i], imax * A[i]);
    		imin = min(A[i], imin * A[i]);

    		r = max(r, imax);
    	}
    	return r;
    }
};



int main(int argc, char const *argv[])
{
	int a[4] = {2,3,-2,4};
	int b[9] = {3,4,5,-1,2,3,-2,5,6};
	int c[5] = {1,2,0,1,1};
	int d[5] = { -2,-3,-5,-1,2};
	Solution s;
	cout<<s.maxProduct(d,5);
	return 0;
}