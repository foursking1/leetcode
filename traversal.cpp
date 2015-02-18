#include <iostream>
#include <stack>


using namespace std;



//Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
		stack<TreeNode *> S;
		vector<int> vec;
				
		if(root == NULL)
			return vec;
		
		TreeNode * Node = NULL;
		S.push(root);
		while( !S.empty())
		{
			Node = S.top();
			if (Node->left == NULL && Node->right == NULL)
			{
				vec.push_back(Node->val);
				S.pop();
			}
			else
			{
				if(Node->right)
				{
					S.push(Node->right);
					Node->right = NULL;
				}
				if(Node->left)
				{
					S.push(Node->left);
					Node->left = NULL;					
				}
			}
		}
		
      }
};

int main()
{
	
}