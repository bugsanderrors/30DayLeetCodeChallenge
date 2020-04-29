/*
    Construct Binary Search Tree from Preorder Traversal

    Return the root node of a binary search tree that matches the given preorder traversal.
    (Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val,
    and any descendant of node.right has a value > node.val.  Also recall that a preorder traversal displays the value of the node first,
    then traverses node.left, then traverses node.right.)

    Example 1:
    Input: [8,5,1,7,10,12]
                    8
                   / \
                  5  10
                 / \   \
                1   7   12
    Output: [8,5,10,1,7,null,12]

    Note: 
        * 1 <= preorder.length <= 100
        * The values of preorder are distinct.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, int& pIndex, int min, int max)
    {
        if (pIndex == preorder.size())
		return NULL;
	
        int val = preorder[pIndex];
        if (val < min || val > max)
            return NULL;

        TreeNode* root = new TreeNode(val);
        pIndex++;

        root->left = buildTree(preorder, pIndex, min, val-1);

        root->right = buildTree(preorder, pIndex, val+1, max);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) 
    {
        int n = preorder.size();
        int preIndex = 0;
        return buildTree(preorder, preIndex, INT_MIN, INT_MAX);    
    }
};