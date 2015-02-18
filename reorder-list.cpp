#include <iostream>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode *head) {
		ListNode *tail = head;
		ListNode *pre = head;
		ListNode *tmp;
		
		//point to the tail
		if ( tail == NULL)
			return ;
		
			
		while( tail->next )
		{
			pre = tail;
			tail = tail->next;
		}

		if( head == tail || head == pre) {
			return;
		}
		

		tmp = head->next;
		head->next = tail;
		pre->next = NULL;	
		tail->next = tmp;
		reorderList( tmp );		
    }
    void reorderListV2(ListNode *head) {
		if (!head || !head->next) return;

    	ListNode *p1 = head;
    	ListNode *p2 = head->next;

    	while( p2 && p2->next)
    	{
    		p1 = p1->next;
    		p2 = p2->next->next;
    	}

    	//reverse
    	ListNode *head2 = p1->next;
    	p1->next = NULL;

    	p2 = head2->next;
    	head2->next = NULL;
    	while(p2) {
    	    p1 = p2->next;
    	    p2->next =head2;
    	    haed2 = p2;
    	    p2 = p1;
    	}

    	//merge
    	for( p1 = head, p2 = head2; p1 ;)
    	{
    		auto t = p1->next;
    		p1->

    	}


    }
};
int main(int argc, char const *argv[])
{
	ListNode *head;

	
	return 0;
}


void reorderList(ListNode *head) {
    if (!head || !head->next) return;

    // find the middle node: O(n)
    ListNode *p1 = head, *p2 = head->next;
    while (p2 && p2->next) {
        p1 = p1->next;
        p2 = p2->next->next;
    }

    // cut from the middle and reverse the second half: O(n)
    ListNode *head2 = p1->next;
    p1->next = NULL;

    p2 = head2->next;
    head2->next = NULL;
    while (p2) {
        p1 = p2->next;
        p2->next = head2;
        head2 = p2;
        p2 = p1;
    }

    // merge two lists: O(n)
    for (p1 = head, p2 = head2; p1; ) {
        auto t = p1->next;
        p1->next = p2;
        p1 = p1->next
        p2 = t;
    }

    //for (p1 = head, p2 = head2; p2; ) {
    //    auto t = p1->next;
    //    p1->next = p2;
    //    p2 = p2->next;
    //    p1 = p1->next->next = t;
    //}
}
