/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/nth-to-last-node-in-list
@Language: C++
@Datetime: 16-06-08 17:18
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
     * @param n: An integer.
     * @return: Nth to last node of a singly linked list. 
     */
    ListNode *nthToLast(ListNode *head, int n) {
        // write your code here
        if (head == NULL) {
            return head;
        }
        int length = 0;
        ListNode* start = head;
        while (start != NULL) {
            ++length;
            start = start->next;
        }
        if (n > length || n <= 0) return NULL;
        if (n == length) return head;
        ListNode* fast = head;
        ListNode* slow = head;
        while (n > 0) {
            fast = fast->next;
            --n;
        }
        while (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};


