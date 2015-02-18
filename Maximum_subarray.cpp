#include <iostream>

using namespace std;

class Solution {
public:
    int maxSubArray(int A[], int n) {
		return maxSubArray_help(A, 0 , n - 1);
    }

	int maxSubArray_help(int A[], int left , int right)
	{
		if ( left == right)
			return A[left];
		int middle = left + ( right - left ) / 2;
		int left_sum = maxSubArray_help(A , left , middle);
		int right_sum = maxSubArray_help(A , middle + 1 , right);
		int cross_sum = find_cross_mid_maxSubArray( A , left , middle , right);
		
		cout << "left" <<left_sum << "right" <<right_sum << "cross" << cross_sum <<endl;
		if ( left_sum >= right_sum && left_sum >=cross_sum)
			return left_sum;
		if ( right_sum >= left_sum && right_sum >=cross_sum)
			return right_sum;
		if ( cross_sum >= right_sum && cross_sum >=left_sum)
			return cross_sum;		
	}
	int find_cross_mid_maxSubArray(int A[], int left , int middle , int right)
	{
		int left_sum = A[middle];
		int sum = 0;
		for (int i = middle ; i >= left ; i--)
		{
			sum = sum + A[i];
			if ( sum > left_sum )
				left_sum = sum;
		}
		
		int right_sum = A[middle + 1];
		sum = 0;
		for (int i = middle + 1 ; i <= right ; i++)
		{
			sum = sum + A[i];
			if ( sum > right_sum )
				right_sum = sum;
		}
		
		return left_sum + right_sum;
	}
}solution;

int main()
{
	int A[2] = { -2,1};
	cout << solution.maxSubArray(A,2)<<endl;
}