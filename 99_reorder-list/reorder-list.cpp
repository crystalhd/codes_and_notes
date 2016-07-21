/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/reorder-list
@Language: C++
@Datetime: 16-07-17 01:17
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
     * @return: void
     */
    void reorderList(ListNode *head) {
        // write your code here
        if (head == NULL) return;
        int size = 0;
        ListNode* start = head;
        while (start != NULL) {
            ++size;
            start = start->next;
        }
        if (size == 1 || size == 2) return;
        int count = 0;
        start = head;
        ListNode* firstEnd = head;
        while (count < size/2) {
            firstEnd = start;
            start = start->next;
            ++count;
        }
        firstEnd->next = NULL;
        ListNode* prev = NULL;
        while (start != NULL) {
            ListNode* next = start->next;
            start->next = prev;
            prev = start;
            start = next;
        }
        ListNode* first = head;
        ListNode* second = prev;
        while (first!=NULL && second!=NULL) {
            ListNode* tmp1 = first->next;
            first->next = second;
            ListNode* tmp2 = second->next;
            if (tmp1 != NULL) {
                second->next = tmp1;
            }
            first = tmp1;
            second = tmp2;
        }
        return;
    }
};


