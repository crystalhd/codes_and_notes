/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/remove-linked-list-elements
@Language: C++
@Datetime: 16-05-03 19:09
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
     * @param val an integer
     * @return a ListNode
     */
    ListNode *removeElements(ListNode *head, int val) {
        // Write your code here
        if (head == NULL) return NULL;
        
        while (head!=NULL && head->val == val)
        {
            head = head->next;
        }
        
        ListNode* start = head;
        while(start!=NULL && start->next!=NULL)
        {
            
            while (start->next!=NULL && start->next->val == val)
            {
                start->next = start->next->next;
            }
            start = start->next;
            
        }
     
        return head;
        
    }
};