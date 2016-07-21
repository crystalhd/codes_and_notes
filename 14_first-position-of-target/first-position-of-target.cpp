/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/first-position-of-target
@Language: C++
@Datetime: 16-07-08 16:32
*/

class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target number to find.
     * @return: The first position of target. Position starts from 0. 
     */
    int binarySearch(vector<int> &array, int target) {
        // write your code here
        if (array.size() == 0) return -1;
        int begin = 0;
        int end = array.size() - 1;
        while (begin < end) {
            int mid = begin + (end-begin)/2;
            if (array[mid] == target) {
                while (mid > 0 && array[mid] == array[mid-1]) {
                    --mid;
                }
                return mid;
            }
            if (mid == begin) {return -1;};
            if (array[mid] < target) {
                begin = mid;
            } else {
                end = mid;
            }
        }
        return -1;
    }
};