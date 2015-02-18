#include <iostream>
#include <vector>



// class Solution {
// public:
//     int findMin(vector<int> &num) {
//         return binarySearch(num, 0, num.size());
//     }
//     int binarySearch(vector<int> &num, int begin, int end) {
//         if (end - begin < 1) return num[0];
//         int mid = begin + (end - begin) / 2;
//         if ((mid-1 < begin || num[mid-1] > num[mid]) &&
//                 (mid+1 >= end || num[mid] < num[mid+1])) {
//             return num[mid];
//         }
//         int lmin = binarySearch(num, begin, mid);
//         int rmin = binarySearch(num, mid + 1, end);
//         return min(lmin, rmin);
//     }
// };





using namespace std;

class Solution {
public:
    int findMin(vector<int> &num) {
        int left = 0;
        int right = num.size() - 1;
        int middle;
        while(left < right)
        {
        	middle = (left + right)/2;
        	cout << left << middle << right << endl;
            //decresing
            if(num[left] > num[middle]) {
                right = middle;
            }
            else if(num[middle+1] > num[right]) {
                left = middle + 1;
            }

            // left == middle == middle+1 == right
            else if(num[left] == num[middle] && num[middle+1] == num[right] && num[middle] == num[middle+1]){
                int inTheLeft = 0;
                for(int i = left; i <= middle; i++){
                    if(num[i] < num[left]) {
                        inTheLeft = 1;
                        break;             
                    }    
                }

                if(inTheLeft == 1)
                    right = middle;
                else
                    left = middle+1;

            }
            else {
            //non decresing
                if(num[left]<num[middle+1])
                    return num[left];
                else
                    return num[middle+1];
            }

        }
        return num[left];

    }
};


int main(int argc, char const *argv[])
{
	vector<int> a = { 2 ,4, 5, 6,6, 7,0, 0, 1,2,2,2,2, 2};
    vector<int> b = { 1,3};	
    vector<int> c = { 1 , 3 , 3};	
    vector<int> d = { 3 , 1 , 3 , 3};	
    vector<int> e = { 3 , 3 , 1 , 3};   
    vector<int> f = { 4 , 4 , 2 , 2};           
    vector<int> g = { 10 , 1 , 10 , 10 , 10};   

	Solution s;
	cout << s.findMin(g);
	return 0;
}