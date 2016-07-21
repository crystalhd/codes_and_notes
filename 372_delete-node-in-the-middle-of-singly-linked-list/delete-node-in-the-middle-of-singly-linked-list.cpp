/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/delete-node-in-the-middle-of-singly-linked-list
@Language: C++
@Datetime: 16-06-08 17:58
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
 */
class Solution {
public:
    /**
     * @param node: a node in the list should be deleted
     * @return: nothing
     */
    void deleteNode(ListNode *node) {
        // write your code here
        /*
        if (node == NULL || node->next == NULL) {
            node = NULL;
        }
        ListNode* start = node;
        int length = 0;
        while (start != NULL) {
            ++length;
            start = start->next;
        }
        int mid = length / 2;
        start = node;
        while (mid > 1) {
            start = start->next;
            --mid;
        }
        start->next = start->next->next;*/
        if (node == NULL || node->next == NULL) {
            node = NULL;
        }
        node->val = node->next->val;
        node->next = node->next->next;
    }
};