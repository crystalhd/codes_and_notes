/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/convert-sorted-list-to-balanced-bst
@Language: C++
@Datetime: 16-06-08 17:46
*/

/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
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
     * @param head: The first node of linked list.
     * @return: a tree node
     */
    TreeNode *sortedListToBST(ListNode *head) {
        // write your code here
        if (head == NULL) {
            return NULL;
        }
        int length = 0;
        ListNode* start = head;
        while (start != NULL) {
            ++length;
            start = start->next;
        }
        if (length == 1) {
            return new TreeNode (head->val);
        }
        int mid = length / 2;
        ListNode* right = head;
        int count = 1;
        while (count < mid) {
            ++count;
            right = right->next;
        }
        ListNode* tmp = right;
        TreeNode* result = new TreeNode (right->next->val);
        right = right->next->next;
        tmp->next = NULL;
        result->left = sortedListToBST(head);
        result->right = sortedListToBST(right);
        return result;
        
    }
};


