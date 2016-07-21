/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/binary-tree-inorder-traversal
@Language: C++
@Datetime: 16-06-13 16:02
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
     * @return: Inorder in vector which contains node values.
     */
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // write your code here
        std::vector<int> result;
        if (root == NULL) return result;
        std::stack<TreeNode*> record;
        //record.push(root);
        TreeNode* current = root;
        while(current != NULL || !record.empty()) {
            while (current != NULL) {
                record.push(current);
                current = current->left;
            }
            current = record.top();
            record.pop();
            result.push_back(current->val);
            if (current->right != NULL) {
                current = current->right;
                continue;
            }
            current = current->right;
        }
        return result;
    }
};