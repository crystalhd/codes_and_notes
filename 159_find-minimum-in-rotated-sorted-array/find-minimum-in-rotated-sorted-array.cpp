/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/find-minimum-in-rotated-sorted-array
@Language: C++
@Datetime: 16-07-08 16:45
*/

class Solution {
public:
    /**
     * @param num: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &num) {
        // write your code here
        int size = num.size();
        if (size == 0) return 0;
        if (size == 1) return num[0];
        int start = 0;
        int end = size - 1;
        while(start+1 < end) {
            int mid = start + (end-start+1)/2;
            if (num[mid] > num[end]) {
                start = mid;
            } else {
                end = mid;
            }
        }
        return std::min(num[start], num[end]);
    }
};