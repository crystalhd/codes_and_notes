/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/remove-node-in-binary-search-tree
@Language: C++
@Datetime: 16-07-18 04:01
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
     * @param value: Remove the node with given value.
     * @return: The root of the binary search tree after removal.
     */
    TreeNode* removeNode(TreeNode* root, int value) {
        // write your code here
        if (root == NULL) return NULL;
        if (root->left == NULL && root->right == NULL) {
            if (root->val == value) return NULL;
            else return root;
        }
        TreeNode* dummy = new TreeNode (-1);
        dummy->right = root;
        TreeNode* cur = root;
        TreeNode* prev = dummy;
        while (cur!=NULL) {
            
            if (cur->val < value) {
                prev = cur;
                cur = cur->right;
            } else if (cur->val > value) {
                prev = cur;
                cur = cur->left;
            } else {
                if (prev->left == cur) {
                prev->left = adjust(cur);
                } else {
                    prev->right = adjust(cur);
                }
                break;
            }
        }
        root = dummy->right;
        delete dummy;
        return root;
    }
    TreeNode* adjust(TreeNode* cur) {
        if (cur->left == NULL && cur->right == NULL) return NULL;
        if (cur->left == NULL) return cur->right;
        if (cur->right == NULL) return cur->left;
        TreeNode* rightLeft = cur->left->right;
        TreeNode* leftRight = cur->right->left;
       
        while (leftRight!=NULL && leftRight->left != NULL) {
            leftRight = leftRight->left;
        }
        if (leftRight != NULL) {
            leftRight->left = rightLeft;
        }
        cur->left->right = cur->right;
        return cur->left;
    }
};