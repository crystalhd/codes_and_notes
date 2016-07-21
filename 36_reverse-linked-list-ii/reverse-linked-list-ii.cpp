/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/reverse-linked-list-ii
@Language: C++
@Datetime: 16-05-29 19:46
*/

/**
 * Definition of singly-linked-list:
 * 
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The head of linked list.
     * @param m: The start position need to reverse.
     * @param n: The end position need to reverse.
     * @return: The new head of partial reversed linked list.
     */
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // write your code here
        if (head == NULL) return head;
        ListNode* start = head;
        int i = 1;
        while (i < m-1) {
            start = start -> next;
            ++i;
        }
        ListNode* prev = (m==1) ? new ListNode(-1) : start;
        ListNode* segCur = (m == 1) ? head : start->next;
        if (m != 1)
        {
            ++i;
        }
        ListNode* segPrev = NULL;
        ListNode* end = segCur;
        while (i <= n) {
            ListNode* next = segCur -> next;
            segCur -> next = segPrev;
            segPrev = segCur;
            segCur = next;
            ++i;
        }
        prev -> next = segPrev;
        end -> next = segCur;
        if (m == 1) {
            return segPrev;
        }
        else {
            return head;
        }
    }
};
