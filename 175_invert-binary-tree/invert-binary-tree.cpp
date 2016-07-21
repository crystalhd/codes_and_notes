/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/invert-binary-tree
@Language: C++
@Datetime: 16-05-30 18:15
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
    void invertBinaryTree(TreeNode *root) {
        // write your code here
        /* recursive
        if (root == NULL || (root->left == NULL && root->right == NULL)) return;
        invertBinaryTree(root->left);
        invertBinaryTree(root->right);
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        return;
        */
        if (root == NULL || (root->left == NULL && root->right == NULL)) return;
        std::queue<TreeNode*> record;
        record.push(root);
        while (record.size() > 0) {
            TreeNode* current = record.front();
            record.pop();
            TreeNode* tmp = current->left;
            current->left = current->right;
            current->right = tmp;
            if (current->left) {
                record.push(current->left);
            }
            if (current->right) {
                record.push(current->right);
            }
        }
        return;
    }
};