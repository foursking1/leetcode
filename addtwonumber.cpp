#include <iostream>
#include <vector>
#include <Algorithm>
#include <stack>

using namespace std;

 
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
  		
    	int sum = 0;
    	ListNode *head = new ListNode(0);
    	ListNode *ptr = head;


  		whie( l1 || l2) {
  			sum = sum/10;
  			if(l1) {
  				sum += l1->val;
  				l1 = l1->next;
  			}

  			if(l2) {
  				sum += l2->val;
  				l2 = l2->next;
  			}

  			ptr->next = new ListNode(sum % 10);
  			ptr = ptr->next;
  		}

  		if( sum / 10 == 1)
  			ptr->next = ListNode(1);

  		return head->next;

    }

    ListNode* create(int a[], int n) {
    	ListNode *head = NULL;
    	ListNode *ptr = NULL;
    	for(int i = n-1; i >= 0; i --) {
    		ptr = new ListNode(a[i]);
    		ptr->next = head;
    		head = ptr;
    	}

    	ptr = head;
		while(ptr) {
			//cout << ptr->val << " " << endl;
			ptr = ptr->next;
		} 
		return head;	
    }
};

int main(int argc, char const *argv[])
{	
	int a[5] = {1,2,3,4,5};
	int b[5] = {1,3,4,5,6};
	Solution *s = new Solution();
	ListNode *p1 = s->create(a,5);
	ListNode *p2 = s->create(b,5);
	s->addTwoNumbers(p1,p2);

	return 0;
}