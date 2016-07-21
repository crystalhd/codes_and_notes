/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/binary-tree-preorder-traversal
@Language: C++
@Datetime: 16-06-13 18:10
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
     * @return: Preorder in vector which contains node values.
     */
    vector<int> preorderTraversal(TreeNode *root) {
        // write your code here
        std::vector<int> result;
        if (root == NULL) {
            return result;
        }
        TreeNode* current = root;
        std::stack<TreeNode*> record;
        while (current != NULL || !record.empty()) {
            while (current != NULL) {
                result.push_back(current->val);
                record.push(current);
                current = current->left;
            }
            current = record.top();
            record.pop();
            /*if (current->right != NULL) {
                current = current->right;
                continue;
            }*/
            current = current->right;
        }
        return result;
    }
};
