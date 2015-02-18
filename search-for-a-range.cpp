#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
		vector<int> vec;
		
		if ( target > A[n-1] || target < A[0])
		{
			vec.push_back(-1);
			vec.push_back(-1);
			return vec;			
		}
		
		int index = searchRange_help( A , 0 , n - 1 , target);
		
		if ( index == - 1)
		{
			vec.push_back(-1);
			vec.push_back(-1);
			return vec;			
		}
		
		
		int left_index = index;
		while( left_index >= 0)
		{
			if ( A[left_index] == target)
				left_index --;
			else
				break;
		}
		vec.push_back( left_index + 1);
		
		int right_index = index;
		
		while( right_index < n)
		{
			if ( A[right_index] == target)
				right_index ++;
			else
				break;
		}
		vec.push_back( right_index - 1);
		
		return vec;

    }
	
	int searchRange_help(int A[] , int begin , int end , int target )
	{

		int middle = ( begin + end ) / 2 ;
		
		if ( end - begin == 0 )
		{
			if ( A[begin] != target )
				return -1;
		}
	
		if( A[middle] == target )
		{
			return middle;
		}
		
		else if( A[middle] < target)
		{
			return searchRange_help( A , middle + 1, end , target);
		}
		else
		{
			return searchRange_help( A , begin , middle - 1, target);
		}
	
		
	}
}solution;


int main()
{
	int A[2] = { 1 , 5};
	vector<int> vec;
	vec = solution.searchRange(A , 2 , 4);
	cout << vec[0] <<  " " << vec[1] << endl;
}