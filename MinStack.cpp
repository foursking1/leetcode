#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;


// class MinStack {
// private:
// 	deque<int> values;	

// public:
//     void push(int x) {
//     	values.push_back(x);   
//     }

//     void pop() {
//     	if (values.size()) {
//     		values.pop_back();
//     	}
//     	else {
//     		return;
//     	}

//     }

//     int top() {
//     	if (values.size()) {
//         	return values.back();
//     	}
//     	else {
//     		return 0;
//     	}
//     }

//     int getMin() {
//     	deque<int>::iterator it;
//         if (values.size()) {
//         	it =  min_element(values.begin(), values.end());
//         	return *it;
//         }
//         else
//         {
//         	return 0;
//         }
//     }
// };



class MinStack {
private:
	deque<int> values;	
	deque<int> mins;

public:
    void push(int x) {
    	int min = mins.size() ? mins.back() : x;
    	values.push_back(x);
    	if (x <= min)
    		mins.push_back(x); 
    }

    void pop() {
    	if (values.back() == mins.back())
    		mins.pop_back();
    	values.pop_back();

    }

    int top() {
 		return values.back();
 	}

    int getMin() {
    	return mins.back();
    }
};

int main(int argc, char const *argv[])
{
	MinStack stack;
	stack.push(1);
	stack.push(2);
	stack.push(4);
	cout << stack.top() << stack.getMin() << endl;
	stack.pop();
	cout << stack.top() << endl;
	stack.pop();
	cout << stack.top() << endl;
	stack.pop();

	return 0;
}







