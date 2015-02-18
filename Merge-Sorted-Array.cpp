//Given two sorted integer arrays A and B, merge B into A as one sorted array.
#include <iostream>
#include <cstdlib>

using namespace std;


class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
		if ( n < 1)
			return ;
		int k = m + n - 1;
		int i = m - 1;
		int j = n - 1;
		
		while( i >= 0 && j >= 0)
		{
			A[k--] = A[i] > B[j] ? A[i--] : B[j--];  
		}
		
		while( j>=0 ) A[k--] = B[j--];  
		

		
    }
};


int main()
{
	
}