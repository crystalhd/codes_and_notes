/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/validate-binary-search-tree
@Language: C++
@Datetime: 16-07-17 22:16
*/

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
    bool isValidBST(TreeNode *root) {
        // write your code here
        if (root == NULL || (root->left == NULL && root->right == NULL)) return true;
        return helper(root, std::numeric_limits<long>::min(), std::numeric_limits<long>::max());
    }
    bool helper (TreeNode* root, long min, long max) {
        if (root == NULL) return true;
        if (!(root->val > min && root->val < max)) return false;
        return helper(root->left, min, root->val) && helper(root->right, root->val, max);
    }
};