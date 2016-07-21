/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/partition-array
@Language: C++
@Datetime: 16-06-03 17:39
*/

class Solution {
public:
    int partitionArray(vector<int> &nums, int k) {
        // write your code here
        int size = nums.size();
        if (size == 0) return 0;
        int begin = 0;
        int end = size - 1;
        while (begin <= end && begin < size && end < size) {
            if (nums[begin] < k) {
                ++begin;
                continue;
            }
            if (nums[end] >= k) {
                --end;
                continue;
            }
            if (begin == end) {
                return begin;
            }
            int tmp = nums[end];
            nums[end] = nums[begin];
            nums[begin] = tmp;
            ++begin;
            --end;
        }
        return begin;
    }
};