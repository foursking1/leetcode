#include <iostream>
#include <vector>


using namespace std; 

struct ListNode {
 	int val;
  	ListNode *next;
  	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        ListNode *returnList = NULL;
        ListNode *it = head;
        while(it)
        {
            int notfound = 0;
            if(returnList == NULL)
            {
                returnList = new ListNode(it->val);
                it=it->next;
                continue;
            }
            ListNode *it2 = returnList;
            ListNode *it2_prev = NULL;
           

            while(it2){

                 if( (it->val < it2->val) )
                 {
                     if(it2_prev == NULL)
                     {
                         ListNode *tmp = new ListNode(it->val);
                         tmp->next = returnList;
                         returnList = tmp;
                     } else {
                         ListNode *node = new ListNode(it->val);
                         it2_prev->next = node;
                         node->next = it2;
                     }
                     break;
                 } 
             it2_prev = it2;
             it2 = it2->next; 
             notfound = 1;
            }


            //point to last one
            if( (notfound == 1)&&(it2 == NULL)){
                ListNode *tmp = new ListNode(it->val);
                //cout << "ss" <<it2_prev->val <<endl; 
                it2_prev->next = tmp;
            }

            it=it->next;
        }
      	return returnList;
    }
};


ListNode * Listcreate(vector<int> &vec)
{

	ListNode *head = NULL;
	ListNode *cur = NULL;
	for (int i = 0; i <  vec.size(); i++) {
		if(i == 0){
			ListNode *element = new ListNode(vec[i]);
			head = element;
			cur = element;			
		} else {
			ListNode *element = new ListNode(vec[i]);
			cur->next = element;
			cur = cur->next;			
		}

	}
	return head;
}

void tranverseList(ListNode *head)
{
	while(head)
	{
		cout << head->val;
		head = head->next;
	}
}

int main(int argc, char const *argv[])
{
	vector<int> vec = {};
	Solution s;
	ListNode *head = Listcreate(vec);
	ListNode *returnList = s.insertionSortList(head);
    tranverseList(returnList);
	return 0;
}