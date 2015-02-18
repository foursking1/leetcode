#include <iostream>
#include <vector>
#include <Algorithm>

using namespace std;


// Definition for singly-linked list.
 struct ListNode {
     int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
    	if( lists.size() == 0)
    		return NULL;

    	if( lists.size() == 1)
    		return lists[0];

    	int k = lists.size() / 2;
    	vector<ListNode *>::iterator it = lists.begin();
    	while(k--) it++;
    	vector<ListNode *> vleft(lists.begin(), it);
    	vector<ListNode *> vright(it, lists.end());
		ListNode *left = mergeKLists(vleft);
		ListNode *right = mergeKLists(vright);

		ListNode *head =  new ListNode(-1);
		ListNode *p = head;

		while( left || right )
		{
			if( right == NULL || ( left && left->val < right->val) )
			{
				p->next = new ListNode(left->val);
				left = left->next;
			}
			else
			{
				p->next = new ListNode(right->val);
				right = right->next;
			}
			p = p->next;
		}
		return head->next;

    }


};

int main(int argc, char const *argv[])
{	
	vector<int> v1 = {1,2};
	vector<int> v2 = {3,4};
	Solution *s = new Solution();
	//ListNode *head = s->mergeKLists()

	return 0;
}