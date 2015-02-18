#include <iostream>
#include <vector>
#include <list>

using namespace std;


// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
		vector<vector<int> > v1;
		if ( root != NULL)
		{
			vector<TreeNode *> pre, cur;
			pre.push_back(root);
			int dir = 1;
			
			while( !pre.empty() )
			{
				vector<int> tmp;
				if ( dir == 1)
				{
					for ( int i = 0 ; i < pre.size() ; i ++)
					{
						tmp.push_back( pre[i]->val );
					}
				}
				else
				{
					for ( int i = pre.size() - 1 ; i >= 0 ; i --)
					{
						tmp.push_back( pre[i]->val );
					}
				}	
				v1.push_back(tmp);
				cur.clear();
				
				for( vector<TreeNode *>::iterator iter = pre.begin() ; iter != pre.end() ; iter ++)
				{
					if ( (*iter)->left != NULL)
					{
						cur.push_back( (*iter)->left );
					}
					if( (*iter)->right != NULL)
					{
						cur.push_back( (*iter)->right );
					}
				}
				
				pre = cur;
				dir = -dir;
			}
			
		}
		return v1;
		
		
    }
    vector<vector<int> > levelOrder(TreeNode *root) {
		vector<vector<int> > v1;
		if ( root != NULL)
		{
			list<TreeNode *> pre, cur;
			pre.push_back(root);
			while( !pre.empty() )
			{
				vector<int> tmp;
				for ( list<TreeNode *>::iterator iter = pre.begin() ; iter != pre.end() ; iter ++)
				{
					tmp.push_back( (*iter)->val );
				}
				v1.push_back(tmp);
				cur.clear();
				
				for( list<TreeNode *>::iterator iter = pre.begin() ; iter != pre.end() ; iter ++)
				{
					if ( (*iter)->left != NULL)
					{
						cur.push_back( (*iter)->left );
					}
					if( (*iter)->right != NULL)
					{
						cur.push_back( (*iter)->right );
					}
				}
				
				pre = cur;
			}
			
		}
		return v1;
    }

    vector<vector<int> > levelOrderBottom(TreeNode *root) {
		vector<vector<int> > v1;	
		vector<vector<int> > result;
		
		if ( root != NULL)
		{
			vector<TreeNode *> pre, cur;
			pre.push_back(root);
			while( !pre.empty() )
			{
				vector<int> tmp;
				for ( vector<TreeNode *>::iterator iter = pre.begin() ; iter != pre.end() ; iter ++)
				{
					tmp.push_back( (*iter)->val );
				}
				v1.push_back(tmp);
				cur.clear();
				
				for( vector<TreeNode *>::iterator iter = pre.begin() ; iter != pre.end() ; iter ++)
				{
					if ( (*iter)->left != NULL)
					{
						cur.push_back( (*iter)->left );
					}
					if( (*iter)->right != NULL)
					{
						cur.push_back( (*iter)->right );
					}
				}
				
				pre = cur;
			}
			
			for ( int i = v1.size() - 1 ; i >= 0 ; i -- )
			{
				vector<int> tmp;
				for ( int j = 0 ; j < v1[i].size() ; j ++)
				{
					tmp.push_back( v1[i][j] );
				}
				result.push_back(tmp);
			}
		
			
		}
		
		return result;
		
    }
};


int main()
{
	
}