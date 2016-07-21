/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/swap-nodes-in-pairs
@Language: C++
@Datetime: 16-06-20 03:59
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
     * @param head a ListNode
     * @return a ListNode
     */
    ListNode* swapPairs(ListNode* head) {
        // Write your code here
        if (head == NULL || head->next == NULL) return head;
        ListNode* phead = new ListNode(0);
        ListNode* front = phead;
        ListNode* prev = head;
        while(prev && prev->next) {
            ListNode* current = prev->next;
            ListNode* tmp = current->next;
            current->next = prev;
            prev->next = tmp;
            front->next = current;
            front = prev;
            prev = tmp;
        }
        if (prev) {
            front->next = prev;
        }
        head = phead->next;
        return head;
    }
};