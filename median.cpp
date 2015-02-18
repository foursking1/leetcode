#include <iostream>
#include <vector>
#include <Algorithm>

using namespace std;

class Solution {
public:
	int findkth(int a[], int m, int b[], int n, int k) {

		if( m == 0)
			return b[k-1];
		if( n == 0)
			return a[k-1];

		if( k == 1) 
			return min(a[0], b[0]);

		int ia = m / 2;
		int ib = m / 2;

		cout << m << " " << n << " " << k << " " << endl;

		if( k > ia + ib ) {
			if( a[ia-1] > b[ib-1] )
				return findkth( a, m , b + ib, n - ib, k - ib );
			else
				return findkth( a + ia , m - ia , b , n , k - ia );
		} 
		else{
			if( a[ia] > b[ib] )
				return findkth( a, m - ia , b , n, k);
			else
				return findkth( a, m , b , n - ib , k);
		}

		return 0;
	}
};

int main(int argc, char const *argv[])
{	
	int a[2] = {1,3};
	int b[1] = {2};
	Solution *s = new Solution();
	cout << s->findkth(a,2,b,1,2);
	return 0;
}