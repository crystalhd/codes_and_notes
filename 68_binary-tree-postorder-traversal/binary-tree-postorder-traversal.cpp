/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/binary-tree-postorder-traversal
@Language: C++
@Datetime: 16-06-13 17:56
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
    /**
     * @param root: The root of binary tree.
     * @return: Postorder in vector which contains node values.
     */
public:
    vector<int> postorderTraversal(TreeNode *root) {
        // write your code here
        std::vector<int> result;
        if (root == NULL) return result;
        std::stack<TreeNode*> record;
        TreeNode* current = root;
        record.push(current);
        TreeNode* prev = NULL;
        while (!record.empty()) {
            current = record.top();
            if (!prev || prev->left == current || prev->right == current) {
                if (current->left) {
                    record.push(current->left);
                } else if (current->right) {
                    record.push(current->right);
                } else {
                    result.push_back(current->val);
                    record.pop();
                }
            } else if (current->left == prev) {
                if (current->right) {
                    record.push(current->right);
                } else {
                    result.push_back(current->val);
                    record.pop();
                }
            } else {
                result.push_back(current->val);
                record.pop();
            }
            prev = current;
        }
        return result;
    }
};