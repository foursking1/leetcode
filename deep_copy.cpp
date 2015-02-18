#include <iostream>
#include <vector>
#include <Algorithm>

using namespace std;

RandomListNode *copyRandomList(RandomListNode *head) {
	RandomListNode *l1, *l2, *newhead;
	if(head == NULL) return NULL;
	for(l1 = head; l1!=NULL; l1 = l1->next->next) {
		l2 = new RandomListNode(l1->label);
		l2->next = l1->next;
		l1->next = l2;
	}

	newhead = head->next;
	for(l1 = head; l1!=NULL; l1->next->next) {
		if(l1->random != NULL) {
			l1->next->random = l1->random->next;
		}
	}

	for(l1 = head; l1!=NULL; l1 = l1->next) {
		l2 = l1->next;
		l1->next = l2->next;
		if(l2->next != NULL) {
			l2->next = l2->next->next;
		}
	}
	return newhead;
}

int main(int argc, char const *argv[])
{	
	return 0;
}