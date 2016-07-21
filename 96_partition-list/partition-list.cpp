/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/partition-list
@Language: C++
@Datetime: 16-05-03 21:33
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
     * @param x: an integer
     * @return: a ListNode 
     */
    ListNode *partition(ListNode *head, int x) {
        // write your code here
        if (head==NULL || (head!=NULL && head->next ==NULL))
        {
            return head;
        }
        ListNode* small = new ListNode (0);
        ListNode* tmpSmall = small;
        ListNode* large = new ListNode (0);
        ListNode* tmpLarge = large;
        bool setSmall = false;
        bool setLarge = false;
        ListNode* start = head;
        
        while(start!=NULL)
        {
            if (start->val < x)
            {
                if (setSmall == false)
                {
                    small->next = start;
                    small = small->next;
                    tmpSmall = small;
                    setSmall = true;
                    start = start->next;
                }
                else
                {
                    tmpSmall->next =  start;
                    start = start->next;
                    tmpSmall = tmpSmall->next;
                }
            }
            else
            {
                if (setLarge == false)
                {
                    large->next = start;
                    large = large->next;
                    tmpLarge = large;
                    setLarge = true;
                    start = start->next;
                }
                else
                {
                    tmpLarge->next = start;
                    start = start->next;
                    tmpLarge = tmpLarge->next;
                }
            }
        
        }
        if (setLarge == false || setSmall == false)
        {
            
            return head;
        }
        else
        {
            tmpSmall->next = large;
            tmpLarge->next = NULL;
            return small;
        }
        
        
    
    }
};


