/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/search-range-in-binary-search-tree
@Language: C++
@Datetime: 16-07-17 23:31
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
     * @param k1 and k2: range k1 to k2.
     * @return: Return all keys that k1<=key<=k2 in ascending order.
     */
    vector<int> searchRange(TreeNode* root, int k1, int k2) {
        // write your code here
        std::vector<int> result;
        helper(root, k1, k2, result);
        std::sort(result.begin(), result.end());
        return result;
    }
    void helper (TreeNode* node, int k1, int k2, std::vector<int>& result) {
        if (node == NULL) {
            return;
        }
        if (node->val >= k1 && node->val <= k2) {
            result.push_back(node->val);
            helper (node->left, k1, k2, result);
            helper(node->right, k1, k2, result);
        } else if (node->val < k1) {
            helper(node->right, k1, k2, result);
        } else {
            helper (node->left, k1, k2, result);
        }
        return;
    }
};