/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/add-two-numbers
@Language: C++
@Datetime: 16-05-28 17:16
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
     * @param l1: the first list
     * @param l2: the second list
     * @return: the sum list of l1 and l2 
     */
    ListNode *addLists(ListNode *l1, ListNode *l2) {
        // write your code here
        ListNode* result = new ListNode(0);
        ListNode* start = result;
        bool flag = false;
        while(l1!=NULL || l2!=NULL)
        {
            int tmp = 0;
            int val1 = l1 == NULL ? 0 : l1->val;
            int val2 = l2 == NULL ? 0 : l2->val;
            
            if (flag == false) tmp = val1+val2;
            else tmp = val1 + val2 + 1;
            
            if (tmp < 10)
            {
                start->next = new ListNode(tmp);
                flag = false;
            }
            else
            {
                start->next = new ListNode(tmp%10);
                flag = true;
            }
            start = start -> next;
            l1 = l1==NULL ? NULL : l1->next;
            l2 = l2==NULL ? NULL : l2->next;
            
        }
        if (flag == true)
        {
            start->next = new ListNode(1);
        }
        start = result->next;
        delete result;
        return start;
    }
};