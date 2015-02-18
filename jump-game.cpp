#include <iostream>

using namespace std;

class Solution {
public:
    bool canJump(int A[], int n) {
	
	// dp method
	        if ( n == 0)
	            return true;
	        if ( n == 1)
	            return true;

	        int dp[n+1];
			for ( int i = 0 ; i <= n ; i ++)
			{
				dp[i] = -1;
			}
			
	        dp[0] = 1;

	        for ( int i = 1 ; i <= n ; i ++ )
	        {
				if ( A[i - 1] >= dp[ i - 1])
					dp[i] = A[i - 1];
				else
					dp[i] = dp[i - 1] - 1;
			
				
				if ( dp[i] <= 0)
					break;
					
	            //cout << dp[i];    
	        }

	        if ( dp[n] >= 0 )
	            return true;
	        else
	            return false;

	    }
}solution;

int main()
{
	int a[3] = { 0 , 2 , 3};
	cout << solution.canJump( a , 3);
	return 0;
}