/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/balanced-binary-tree
@Language: C++
@Datetime: 16-06-11 00:14
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
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode *root) {
        // write your code here
        if (root == NULL) return true;
        if (root->left == NULL && root->right == NULL) return true;
        if (isBalanced(root->left) && isBalanced(root->right)) {
            int left = depth(root->left);
            int right = depth(root->right);
            if (left == right + 1 || right == left + 1 || left == right) {
                return true;
            }
        }
        return false;
    }
    int depth(TreeNode* node) {
        if (node == NULL) return 0;
        if (node->left == NULL && node->right == NULL) return 1;
        int left = depth(node->left);
        int right = depth(node->right);
        return left > right ? left + 1 : right + 1;
    }
};