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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if( head == NULL)
        	return NULL;

        if( k == 1)
        	return head;


        ListNode *sentinel = new ListNode(-1);
        ListNode *start = head;
        ListNode *tail = head;
        ListNode *pre = sentinel;
        ListNode *next = NULL;
        sentinel->next = head;
        


        int num = k;
        while( tail ) {
			//cout << num << endl;
        	if( num == 1)
        	{

        		next = tail->next;
        		tail->next = NULL;
        		ListNode *tmp = reverse(start);
        		pre->next = tmp;
        		while( start->next) start = start->next;

        		pre = start;
        		start->next = next;
        		start = next;
        		tail = next;
        		num = k; 

        	}
        	else {
        		num --;
        		tail = tail->next;
        	}
        	
        }
        return sentinel->next;
    }

    ListNode* reverse( ListNode *head) {
    	ListNode *p1;
    	ListNode *p2;
    	ListNode *pre = NULL;

    	if( head == NULL)
    		return NULL;

    	while(head) {
    		if( head->next == NULL) {
    			head->next = pre;
    			break;
    		} else {
	    		p2 = head;
	    		p1 = head->next;
	    		head->next = pre;
	    		head = p1;
	    		pre = p2;
	    	}
    	}

    	return head;
    }
};

int main(int argc, char const *argv[])
{	
	ListNode *head = new ListNode(1);
	ListNode *cur = head;
	cur->next = new ListNode(2);
	cur = cur->next;
	cur->next = new ListNode(3);
	cur = cur->next;


	Solution *s = new Solution();
	ListNode *ret = s->reverseKGroup(head,3);
	while(ret) {
		cout << ret->val << endl;
		ret = ret->next;
	}


	return 0;
}