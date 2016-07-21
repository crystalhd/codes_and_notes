/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/merge-two-sorted-lists
@Language: C++
@Datetime: 16-06-19 21:17
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
     * @param ListNode l1 is the head of the linked list
     * @param ListNode l2 is the head of the linked list
     * @return: ListNode head of linked list
     */
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // write your code here
        if (l1 == NULL) {return l2; }
        if (l2 == NULL) {return l1; }
        ListNode* phead = new ListNode (0);
        ListNode* current = phead;
        /*while (l1 || l2) {
            int a = l1 ? l1->val : INT_MAX;
            int b = l2 ? l2->val : INT_MAX;
            if (a <= b) {
                current->next = l1;
                current = current->next;
                l1 = l1->next;
            } else {
                current->next = l2;
                current = current->next;
                l2 = l2->next;
            }
        }*/
        while (l1 && l2) {
            if (l1->val < l2->val) {
                current->next = l1;
                l1 = l1->next;
            } else {
                current->next = l2;
                l2 = l2->next;
            }
            current = current->next;
        }
        if (l1) {
            current->next = l1;
        }
        if (l2) {
            current->next = l2;
        }
        ListNode* head = phead->next;
        delete phead;
        return head;
    }
};