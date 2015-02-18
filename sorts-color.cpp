#include <iostream>

using namespace std;


class Solution {
public:
    void sortColors(int A[], int n) {
		int i = 0;
		int j = n - 1;
		while(i != j)
		{
			if( A[i] == 0 )
			{
				i ++;
			}
			if( A[i] == 1 )
			{
				
			}
			if( A[i] == 2 )
			{
				swap( &A[i] , &A[j]);
			}
			
		}
        
    }
	void swap(int *a, int *b)
	{
		*a = *a ^ *b;
		*a = *a ^ *b;
		*a = *a ^ *b;
	}
};


int main()
{
	
}


