/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/construct-binary-tree-from-preorder-and-inorder-traversal
@Language: C++
@Datetime: 16-07-17 23:10
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
     *@param preorder : A list of integers that preorder traversal of a tree
     *@param inorder : A list of integers that inorder traversal of a tree
     *@return : Root of a tree
     */
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // write your code here
        if (preorder.size() == 0) return NULL;
        return buildNode(preorder, inorder);
    }
    TreeNode* buildNode(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) return NULL;
        TreeNode* root = new TreeNode (preorder[0]);
        if (preorder.size() == 1) return root;
        int value = preorder[0];
        int length1 = std::distance(inorder.begin(), std::find(inorder.begin(), inorder.end(), value));
        std::cerr<<"length1: "<<length1<<" ";
        vector<int> leftInorder, leftPreorder;
        vector<int> rightInorder, rightPreorder;
        for (int i = 0; i < length1; ++i) {
            leftInorder.push_back(inorder[i]);
            leftPreorder.push_back(preorder[i+1]);
        }
        for (int i = length1+1; i < preorder.size(); ++i) {
            rightInorder.push_back(inorder[i]);
            rightPreorder.push_back(preorder[i]);
        }
        std::cerr<<leftInorder.size()<<" "<<leftPreorder.size()<<" "<<rightInorder.size()<<" "<<rightPreorder.size()<<" ";
        TreeNode* left = buildNode(leftPreorder, leftInorder);
        TreeNode* right = buildNode(rightPreorder, rightInorder);
        root->left = left;
        root->right = right;
        return root;
    }
};