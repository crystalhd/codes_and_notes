/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/linked-list-cycle
@Language: C++
@Datetime: 16-06-25 20:29
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
     * @param head: The first node of linked list.
     * @return: True if it has a cycle, or false
     */
    bool hasCycle(ListNode *head) {
        // write your code here
        if (head == NULL || head->next == NULL) {
            return false;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        while (slow->next!=NULL && fast->next != NULL && fast->next->next!=NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if ( slow == fast) {
                return true;
            }
        }
        return false;
    }
};


