#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Point {
     int x;
     int y;
     Point() : x(0), y(0) {}
     Point(int a, int b) : x(a), y(b) {}
 };

class Solution {
public:
    int maxPoints(vector<Point> &points) {
    	int max = 0;

    	for(int i = 0; i < points.size(); i++)
    	{
    		//max = 1;
    		map<float, int> m;
    		int zero = 0;
    		for(int j = 0; j < points.size(); j ++)
    		{
    			float key;

    			
    			if ( points[j].x == points[i].x && points[j].y == points[i].y) {
   					zero ++;
   					continue;
    			}
    			else if (points[j].x - points[i].x)
    				key = 1.0 * (points[j].y - points[i].y) / (points[j].x - points[i].x);
    			else
    				key = 1000 * 1.0;

    			
    			//cout<<key<<endl;
    			auto search = m.find(key);
    			if (search != m.end()) 
    				m[key] += 1;
    			else
    				m[key] = 1;
	    	
    		}


    		int maxNum = 0;
    		for (auto i : m) {
    			if (i.second > maxNum)
    				maxNum = i.second;
    		}

    		maxNum += zero;

    		cout << maxNum << " ";
    		if (maxNum > max)
    			max = maxNum;

    	}
    	
    	return max;
        
    }
};

int main()
{
	vector<Point> vec;
	vec.push_back(Point(84,250));
     vec.push_back(Point(0,0));
	 vec.push_back(Point(1,0));
	      vec.push_back(Point(0,-70));
	 vec.push_back(Point(1,-1));
	      vec.push_back(Point(21,10));
	 vec.push_back(Point(42,90));
	      vec.push_back(Point(-42,-23));
	 vec.push_back(Point(0,-70));
	Solution s;
	s.maxPoints(vec);
}




