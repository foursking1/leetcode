#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


class Solution {
public:
    vector<int> getRow(int rowIndex) {
		vector<int> matrix( rowIndex + 1);
		
		for ( int i = 0 ; i < matrix.size() ; i++)
		{
			for ( int k = i ; k >= 0 ; k --)
			{
				if (k == i || k == 0)
					matrix[k] = 1;
				else
					matrix[k] = matrix[k] + matrix[k-1];
			}
		}
		return matrix;
    }
}solution;

int main()
{
	vector<int> res;
	res = solution.getRow(0);
	for(int i = 0 ; i < res.size() ; i++)
	{
		cout << res[i] << " " ;
	}
	cout<<"finish"<<endl;
	
}