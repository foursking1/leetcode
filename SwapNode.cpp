#include <iostream>
#include <vector>
#include <Algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if( head == NULL || head->next == NULL)
        	return head;

        ListNode *sentinel = new ListNode(-1);
        ListNode *front = sentinel;
        ListNode *middle = sentinel;
        ListNode *back = sentinel;
        sentinel->next = head;
        head = sentinel;


        while(front->next) {

        	front = front->next;
        	middle = front;
        	
        	if( front->next )
        	{

        		front = front -> next;        		
        		middle->next = front->next;
        		back->next = front;
        		front->next = middle;
        		front = back = middle;

        	}

        }

        return head->next;

    }
};
int main(int argc, char const *argv[])
{	
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	Solution *s = new Solution();
	ListNode *ret = s->swapPairs(head);
	while(ret) {
		cout << ret->val << endl;
		ret = ret->next;
	}

	return 0;
}