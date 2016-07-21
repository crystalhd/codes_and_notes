/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/remove-nth-node-from-end-of-list
@Language: C++
@Datetime: 16-05-03 21:32
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
     * @return: The head of linked list.
     */
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // write your code here
        ListNode* start = head;
        int length = 0;
        while(start!=NULL)
        {
            ++length;
            start = start->next;
        }
        if (length == n)
        {
            return head->next;
        }
        if (n==0)
        {
            return head;
        }
        int count = 0;
        ListNode* tmp = new ListNode(0);
        tmp->next = head;
        while(count < length-n)
        {
            tmp = tmp->next;
            ++count;
        }
        if (tmp->next!=NULL)
        {
            tmp->next = tmp->next->next;
        }
        
        return head;
        
    }
};


