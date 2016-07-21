/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/remove-duplicates-from-sorted-array
@Language: C++
@Datetime: 16-06-02 04:55
*/

class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        // write your code here
        int size = nums.size();
        if (size == 0 || size == 1) {
            return size;
        }
        int length = 0;
        int current = 0;
        while (length < size && current < size) {
            int num = nums[length];
            while (current < size && nums[current] == num) {
                ++current;
            }
            if (current == size) {
                break;
            }
            int tmp = nums[current];
            nums[current] = nums[length + 1];
            nums[length + 1] = tmp;
            ++length;
            ++current;
        }
        return length + 1;
    }
};