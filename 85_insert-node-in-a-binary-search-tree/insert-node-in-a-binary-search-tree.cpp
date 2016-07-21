/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/insert-node-in-a-binary-search-tree
@Language: C++
@Datetime: 16-07-17 21:40
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
     * @param root: The root of the binary search tree.
     * @param node: insert this node into the binary search tree
     * @return: The root of the new binary search tree.
     */
    TreeNode* insertNode(TreeNode* root, TreeNode* node) {
        // write your code here
        if (root == NULL) {
            return node;
        }
        TreeNode* cur = root;
        TreeNode* prev = root;
        while (cur!=NULL) {
            prev = cur;
            if (node->val > cur->val) {
                cur = cur->right;
            } else {
                cur = cur->left;
            }
        }
        if (node->val > prev->val) {
            prev->right = new TreeNode(node->val);
        } else {
            prev->left = new TreeNode(node->val);
        }
        return root;
    }
};