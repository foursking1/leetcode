#include <iostream>
#include <queue>

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
    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below  
        // DO NOT write int main() function  
          
        if ( !root )  
            return 0;  
        if ( !root->left && !root->right )  
            return 1;  
        int ret=INT_MAX;  
        if ( root->left )  
            ret=minDepth(root->left)+1;  
        if ( root->right)  
            ret=min(ret,minDepth(root->right)+1);  
        return ret;

    }
};

int main()
{
	
}
