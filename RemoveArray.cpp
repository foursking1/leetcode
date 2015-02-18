#include <iostream>
#include <vector>
#include <Algorithm>

using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int ret = 0;
        if( n == 0)
            return 0;
        
        if( n == 1)
            return A[0];
            
        int last = A[0];    
        
        for( int i = 0; i < n ; i ++ ) {
        	if( i == 0) { ret ++; continue;}

        	if( A[i] != last) {
        		//ret ++;
        		A[ret] = A[i];
        		ret ++;
        		last = A[i]; 
        	}
            
        }
        
       return ret; 
    }
};

int main(int argc, char const *argv[])
{	
	int a[] = {1,2,3,4,4,5,5,6,6,7,7};
	Solution *s = new Solution();
	cout << s->removeDuplicates(a,11);
	return 0;
}