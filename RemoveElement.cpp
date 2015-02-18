#include <iostream>
#include <vector>
#include <Algorithm>

using namespace std;

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
      	if( n == 0)
      		return 0;
      	

		int ret = 0;

      	for(int i = 0; i < n; i ++ )
      	{
      		if(A[i] != elem) 
      		{
      			A[ret] = A[i];
      			ret++;
      		}
      	}

      	// for(int i = 0; i < ret; i ++) {
      	// 	cout << A[i] << " ";
      	// }
      	return ret;

    }
};

int main(int argc, char const *argv[])
{	
	int a[] = {1,2,3,4,4,6,5,6,6,7,7};
	Solution *s = new Solution();
	cout << s->removeElement(a,11,6);
	return 0;
}