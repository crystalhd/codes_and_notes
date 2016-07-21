/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/remove-duplicates-from-sorted-list
@Language: C++
@Datetime: 16-05-03 19:19
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
     * @return: head node
     */
    ListNode *deleteDuplicates(ListNode *head) {
        // write your code here
        if (head==NULL || (head!=NULL && head->next==NULL))
            return head;
        
        ListNode* start = head;
        while(start!=NULL && start->next != NULL)
        {
            while (start!=NULL && start->next != NULL && start->val == start->next->val)
            {
                start->next = start->next->next;
            }
            start = start->next;
        }
        if (start!=NULL && start->val == head->val)
        {
            head->next = NULL;
        }
        return head;
    }
};