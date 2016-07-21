/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/rotate-list
@Language: C++
@Datetime: 16-07-16 23:54
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head: the list
     * @param k: rotate to the right k places
     * @return: the list after rotation
     */
    ListNode *rotateRight(ListNode *head, int k) {
        // write your code here
        int n = 0;
        if (head == NULL || head->next == NULL) {
            return head;
        }
        
        ListNode* ite = head;
        while (ite != NULL) {
            ++n;
            ite = ite->next;
        }
        if (k % n == 0) {
            return head;
        }
        
        ListNode* start = new ListNode (0);
        ite = head;
        int count = 1;
        k = k % n;
        
        while (count < (n-k)) {
            ++count;
            ite = ite->next;
        }
        ListNode* prev = ite;
        ListNode* cur = ite->next;
        start->next = cur;
        prev->next = NULL;
        while (cur->next!=NULL) {
            cur = cur->next;
        }
        cur->next = head;
        head = start->next;
        delete start;
        return head;
    }
};