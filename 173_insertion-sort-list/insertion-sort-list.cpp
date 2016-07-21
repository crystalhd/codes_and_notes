/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/insertion-sort-list
@Language: C++
@Datetime: 16-06-19 20:31
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
     * @return: The head of linked list.
     */
    ListNode *insertionSortList(ListNode *head) {
        // write your code here
        if (head == NULL || head->next == NULL) {
            return head;
        }
       /*
        vector<int> valRecord;
        ListNode* current = head;
        while (current != NULL) {
            valRecord.push_back(current->val);
            current = current->next;
        }
        for (int i = 1; i != valRecord.size(); ++i) {
            if (valRecord[i] >= valRecord[i-1]) {
                continue;
            }
            for (int j = i-1; j >= 0 && valRecord[j] > valRecord[i]; --j) {
                int tmp = valRecord[i];
                valRecord[i] = valRecord[j];
                valRecord[j] = tmp;
                i = j;
            }
        }
        current = head;
        int i = 0;
        while (current != NULL) {
            current->val = valRecord[i];
            current = current->next;
            ++i;
        }
        return head;*/
       ListNode* phead = new ListNode(INT_MIN);
       phead->next = head;
       ListNode* front = head;
       head = head->next;
       front->next = NULL;
       while (head) {
           if (head->val >= front->val) {
               front->next = head;
               head = head->next;
               front = front->next;
               front->next = NULL;
               continue;
           }
           ListNode* current = phead;
           ListNode* prev;
           while (current && head->val >= current->val) {
               prev = current;
               current = current->next;
           }
           prev->next = head;
           ListNode* tmp = head->next;
           head->next = current;
           head = tmp;
       }
       head = phead->next;
       delete phead;
       return head;
    }
};