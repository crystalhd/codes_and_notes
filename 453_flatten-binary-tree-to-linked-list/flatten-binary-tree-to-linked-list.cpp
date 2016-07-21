/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/flatten-binary-tree-to-linked-list
@Language: C++
@Datetime: 16-06-13 19:24
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
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void flatten(TreeNode *root) {
        // write your code here
        helper(root);
    }
    void helper(TreeNode* node) {
        if (node == NULL || (node != NULL && node->left == NULL && node->right == NULL)) return;
        helper(node->left);
        helper(node->right);
        if (node->left == NULL) return;
        if (node->right == NULL) {
            node->right = node->left;
            node->left = NULL;
            return;
        } else {
            TreeNode* current = node->left;
            while (current->right != NULL) {
                current = current->right;
            }
            current->right = node->right;
            node->right = node->left;
            node->left = NULL;
        }
    }
};