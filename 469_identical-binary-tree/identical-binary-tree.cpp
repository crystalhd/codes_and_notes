/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/identical-binary-tree
@Language: C++
@Datetime: 16-06-13 19:31
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
     * @aaram a, b, the root of binary trees.
     * @return true if they are identical, or false.
     */
    bool isIdentical(TreeNode* a, TreeNode* b) {
        // Write your code here
        if (a == NULL && b == NULL) return true;
        if ((a && !b) || (!a && b)) return false;
        if (a->left == NULL && a->right == NULL) {
            if (b->left == NULL && b->right == NULL) {
                return a->val == b->val;
            }
            return false;
        }
        if (isIdentical(a->left, b->left)) {
            if (isIdentical(a->right, b->right)) {
                return a->val == b->val;
            }
            return false;
        }
        return false;
    }
};