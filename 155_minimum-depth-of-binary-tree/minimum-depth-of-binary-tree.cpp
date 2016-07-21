/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/minimum-depth-of-binary-tree
@Language: C++
@Datetime: 16-06-02 17:10
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
     * @return: An integer
     */
    int minDepth(TreeNode *root) {
        // write your code here
        if (root == NULL) return 0;
        std::queue<TreeNode*> record;
        record.push(root);
        int cur = 1;
        int next = 0;
        int depth = 1;
        while (!record.empty()) {
            TreeNode* current = record.front();
            record.pop();
            --cur;
            if (current->left == NULL && current->right == NULL) {
                return depth;
            }
            if (current->left) {
                record.push(current->left);
                ++next;
            }
            if (current->right) {
                record.push(current->right);
                ++next;
            }
            if (cur == 0) {
                cur = next;
                next = 0;
                ++depth;
            }
        }
    }
};