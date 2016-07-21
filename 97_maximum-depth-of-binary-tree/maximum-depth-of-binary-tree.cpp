/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/maximum-depth-of-binary-tree
@Language: C++
@Datetime: 16-06-02 15:40
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
    int maxDepth(TreeNode *root) {
        // write your code here
        if (root == NULL) return 0;
        if (root->left == NULL && root->right == NULL) return 1;
        int d1 = maxDepth(root->left);
        int d2 = maxDepth(root->right);
        return d1 > d2 ? (d1 + 1) : (d2 + 1);
    }
};