/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/intersection-of-two-linked-lists
@Language: C++
@Datetime: 16-06-25 20:02
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
     * @param headA: the first list
     * @param headB: the second list
     * @return: a ListNode
     */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // write your code here
        if (headA == NULL || headB == NULL) {
            return NULL;
        }
        int lengthA = 0;
        ListNode* tmpA = headA;
        while (tmpA != NULL) {
            ++lengthA;
            tmpA = tmpA->next;
        }
        int lengthB = 0;
        ListNode* tmpB = headB;
        while (tmpB != NULL) {
            ++lengthB;
            tmpB = tmpB->next;
        }
        int commonLength = std::min(lengthA, lengthB);
        while (lengthA > commonLength) {
            headA = headA->next;
            --lengthA;
        }
        while (lengthB > commonLength) {
            headB = headB->next;
            --lengthB;
        }
        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};