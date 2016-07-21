/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/reverse-linked-list
@Language: C++
@Datetime: 16-05-28 17:55
*/

/**
 * Definition of ListNode
 * 
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 * 
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
     * @return: The new head of reversed linked list.
     */
    ListNode *reverse(ListNode *head) {
        // write your code here
        //ListNode* prev = new ListNode(0);
        ListNode* prev = NULL;
        //prev->next = head;
        ListNode* current = head;
        if (head == NULL || head->next == NULL)
            return head;
        while (current != NULL) {
            ListNode* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        //head->next = NULL;
        return prev;
    }
};
