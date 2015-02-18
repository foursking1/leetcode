#include <iostream>
using namespace std;

//sort this list in n*logn time complexity , in constant space complexity


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode *sortList(ListNode *head) {
		ListNode n(0);
		n.next = head;
		int listlen = 0;
		while(head)
		{
			listlen ++;
			head = head->next;
		}
		
		for ( int len = 1 ; len < listlen ; len *= 2)
		{
			ListNode *t = n.next;
			ListNode *l1,*l2;
			ListNode *h = &n;
			while ( t!=NULL)
			{
				l1 = t;
				l2 = split ( t , len );
				t = split( l2 , len );
				ListNode *tail = merge ( l1 , l2 , h);
				tail->next = t;
				h = tail;
			}
			
		}
		return n.next;
    }
	/*
	ListNode *partition(listNode *begin , ListNode *end)
	{
		int key = end->val;
		ListNode *it;
		ListNode *gt_head;
		ListNode *gt_tail;
		ListNode *lt_head;
		ListNode *lt_tail;
		ListNode *tmp;
		
		gt_tail = gt_head = NULL; //confuse
		lt_tail = lt_head = NULL;
		
		int first_gt = 1;
		int first_lt = 1;
		
		for ( it = begin ; it != end ; it ++)
		{
			if ( it->val >= key)
			{
				if (first_gt)
				{
					gt_head = it;
					gt_tail = it;
					first_gt = 0;
				}
				gt_tail -> next = it;
				gt->tail = gt_tail->next;
			}
			else
			{
				if (first_lt)
				{
					lt_head = it;
					lt_tail = it;
					first_lt = 0;
				}
				lt_tail -> next = it;
				lt->tail = lt_tail->next;
			}
		}
		
		if ( gt_head )
			gt_tail->next = lt_head;
			
	}
	*/
	
	ListNode *merge ( ListNode *l1 , ListNode *l2 , ListNode *h)
	{
		ListNode *l = h;
		while ( l1 || l2)
		{
			if ( !l1)
			{
				l->next = l2;
				l2 = l2->next;
			}
			else if (!l2)
			{
				l->next = l1;
				l1 = l1->next;
			}
			else if ( l1->val < l2->val)
			{
				l->next = l1;
				l1 = l1->next;
			}
			else
			{
				l->next = l2;
				l2 = l2->next;
			}
			l = l->next;
		}
		
		return l;
		
		
	}
	
	ListNode *split( ListNode *h , int len)
	{
		for ( int i = 1 ; i < len && h != NULL ; i ++)
		{
			h = h->next;
		}
		
		if ( h == NULL) return NULL;
		
		ListNode *t = h->next;
		h->next = NULL;
		
		return t;
	}
};


int main()
{
	
	return 0;
}