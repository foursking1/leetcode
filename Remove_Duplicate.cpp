#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
	//	int hash[10] = { 0 };
		if ( head == NULL || head->next == NULL )
			return head;
		//ListNode  *node = head ;
		ListNode *pre = head ;
		ListNode *node = head->next;
	//	hash[ pre->val ] = 1;
		
		while (node)
		{
			if ( pre->val == node->val ) //delete node
			{
				pre->next = node->next;
				delete node;
				node = pre->next;			
			}
			else
			{
			//	hash[ node->val ] = 1;
				node = node->next;
				pre = pre->next;
			}
		}
		return head;
    }
};

int main()
{
	
}