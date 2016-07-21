/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/copy-list-with-random-pointer
@Language: C++
@Datetime: 16-07-17 00:49
*/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
        // write your code here
        if (head==NULL) {
            return NULL;
        }
        RandomListNode* newHead = new RandomListNode (head->label);
        if (head->next == NULL && head->random == NULL) {
            return newHead;
        }
        RandomListNode* start = head;
        while (start != NULL) {
            RandomListNode* tmp = new RandomListNode (start->label);
            RandomListNode* next = start->next;
            start->next = tmp;
            tmp->next = next;
            start = tmp->next;
        }
        start = head;
        while (start != NULL) {
            RandomListNode* random = start->random;
            RandomListNode* next = start->next;
            if (next != NULL && random!=NULL) {
                next->random = random->next;
            }
            start = next->next;
        }
        start = head;
        newHead = head->next;
        while (start != NULL) {
            RandomListNode* tmp = start->next;
            start->next = tmp->next;
            if (tmp->next!=NULL) {
                tmp->next = tmp->next->next;
            }
            start = start->next;
            //start->next->next = start->next->next;
        }
        return newHead;
    }
};