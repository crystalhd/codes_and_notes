/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/binary-tree-paths
@Language: C++
@Datetime: 16-06-13 16:18
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
     * @param root the root of the binary tree
     * @return all root-to-leaf paths
     */
    vector<string> binaryTreePaths(TreeNode* root) {
        // Write your code here
        std::vector<std::string> result;
        if (root == NULL) return result;
        if (root->left == NULL && root->right == NULL) {
            result.push_back(to_string(root->val));
            return result;
        }
        std::queue<TreeNode*> record;
        record.push(root);
        unordered_map<TreeNode*, string> stringRecord;
        stringRecord[root] = to_string(root->val);
        while(!record.empty()) {
            TreeNode* current = record.front();
            record.pop();
            if (current->left == NULL && current->right == NULL) {
                result.push_back(stringRecord[current]);
                continue;
            }
            if (current->left != NULL) {
                string tmpLeft = stringRecord[current] + "->";
                tmpLeft += to_string(current->left->val);
                stringRecord[current->left] = tmpLeft;
                record.push(current->left);
            }
            if (current->right != NULL) {
                string tmpRight = stringRecord[current] + "->";
                tmpRight += to_string(current->right->val);
                stringRecord[current->right] = tmpRight;
                record.push(current->right);
            }
        }
        return result;
    }
};