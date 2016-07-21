/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/first-bad-version
@Language: C++
@Datetime: 16-07-08 21:11
*/

/**
 * class SVNRepo {
 *     public:
 *     static bool isBadVersion(int k);
 * }
 * you can use SVNRepo::isBadVersion(k) to judge whether 
 * the kth code version is bad or not.
*/
class Solution {
public:
    /**
     * @param n: An integers.
     * @return: An integer which is the first bad version.
     */
    int findFirstBadVersion(int n) {
        // write your code here
        if (n==1) return n;
        int start = 1;
        int end = n;
        while (start < end) {
            int mid = start + (end-start)/2;
            if (SVNRepo::isBadVersion(mid) == false) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }
        return start;
    }
};
