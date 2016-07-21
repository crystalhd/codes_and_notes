/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/merge-k-sorted-lists
@Language: C++
@Datetime: 16-07-18 22:52
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
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // write your code here
        ListNode* prev = new ListNode (0);
        int size = lists.size();
        if (size == 0) return NULL;
        if (size == 1) return lists[0];
        std::multimap<int, ListNode*> record;
        for (int i = 0; i < size; ++i) {
            if (lists[i] != NULL) {
                record.insert(std::pair<int, ListNode*>(lists[i]->val, lists[i]));
            }
        }
        std::cerr<<record.size()<<" ";
        ListNode* start = prev;
        while (record.size() > 0) {
            ListNode* top = record.begin()->second;
            start->next = top;
            ListNode* next = top->next;
            record.erase(record.begin());
            if (next != NULL) {
                record.insert(std::pair<int, ListNode*>(next->val, next));
            }
            start = top;
        }
        return prev->next;
    }
};


