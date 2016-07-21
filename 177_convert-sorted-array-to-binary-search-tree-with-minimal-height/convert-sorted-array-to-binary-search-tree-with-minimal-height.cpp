/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/convert-sorted-array-to-binary-search-tree-with-minimal-height
@Language: C++
@Datetime: 16-06-08 17:31
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
     * @param A: A sorted (increasing order) array
     * @return: A tree node
     */
    TreeNode *sortedArrayToBST(vector<int> &A) {
        // write your code here
        if (A.size() == 0) {
            return NULL;
        }
        if (A.size() == 1) {
            return new TreeNode(A[0]);
        }
        int mid = A.size() / 2;
        TreeNode* result = new TreeNode (A[mid]);
        vector<int> A1(A.begin(), A.begin()+mid);
        vector<int> A2(A.begin()+mid+1, A.end());
        result->left = sortedArrayToBST(A1);
        result->right = sortedArrayToBST(A2);
        return result;
    }
};


