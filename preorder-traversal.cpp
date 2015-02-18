#include <iostream>
#include <stack>
#include <vector>


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

		while(!S.empty())
		{
			TreeNode *Node = S.top();
			vec.push_back(Node->val);
			S.pop();
			if(Node->right)
				S.push(Node->right);
			if(Node->left)
				S.push(Node->left);
		}

		return vec;
	}


};

int main()
{
	Solution s;

}






