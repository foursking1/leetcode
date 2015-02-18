#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int> > generate(int numRows) {
		vector<vector<int> > vec;
		
	//	vec[0][0] = 1;
		
        for ( int i = 0 ; i < numRows ; i ++)
		{
			vector<int> tmp(i + 1 , 0);
			vec.push_back(tmp);
			for ( int k = i ; k >= 0 ; k --)
			{
				if ( k == 0 || k == i)
				{
					vec[i][k] = 1;
				}
				else
				{
					vec[i][k] = vec[i-1][k] + vec[i-1][k-1];
				}
			}
		}
		return vec; 
    }
}solution;

int main()
{
	vector<vector<int> > vec = solution.generate(5);
	
	for ( int i = 0 ; i < vec.size() ; i++)
	{
		for (int j = 0 ; j < vec[i].size() ; j++)
		{
			cout << vec[i][j] << "";
		}
		cout << endl;
	}
	
}
