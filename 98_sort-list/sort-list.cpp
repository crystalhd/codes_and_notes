/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/sort-list
@Language: C++
@Datetime: 16-06-25 20:53
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
     * @return: You should return the head of the sorted linked list,
                    using constant space complexity.
     */
    ListNode *sortList(ListNode *head) {
        // write your code here
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* preHead = new ListNode (INT_MIN);
        preHead->next = head;
        ListNode* front = head;
        ListNode* current = head->next;
        
        while(current!=NULL) {
            ListNode* next = current->next;
            if (current->val >= front->val) {
                front->next = current;
                front = front->next;
            }
            else {
                ListNode* start = preHead;
                while (start->val < current->val && start->next->val < current->val) {
                    start = start->next;
                }
                ListNode* tmp = start->next;
                start->next = current;
                current->next = tmp;
            }
            current = next;
        }
        front->next = NULL;
        head = preHead->next;
        delete preHead;
        return head;
    }
};


