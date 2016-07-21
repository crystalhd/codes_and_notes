/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/binary-tree-level-order-traversal
@Language: C++
@Datetime: 16-07-17 23:21
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
     * @return: Level order a list of lists of integer
     */
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        // write your code here
        std::vector<std::vector<int>> result;
        if (root == NULL) return result;
        std::queue<TreeNode*> record;
        record.push(root);
        int length = 1;
        int nextLength = 0;
        while (length > 0) {
            std::vector<int> tmp;
            while(length > 0)
            {
                TreeNode* current = record.front();
                tmp.push_back(current->val);
                record.pop();
                if (current->left != NULL) {
                    ++nextLength;
                    record.push(current->left);
                }
                if (current->right != NULL) {
                    record.push(current->right);
                    ++nextLength;
                }
                --length;
            }
            result.push_back(tmp);
            length = nextLength;
            nextLength = 0;
        }
        return result;
    }
};
