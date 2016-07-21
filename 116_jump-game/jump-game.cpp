/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/jump-game
@Language: C++
@Datetime: 16-07-15 21:12
*/

class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: The boolean answer
     */
    bool canJump(vector<int> A) {
        // write you code here
        int size = A.size();
        if (size == 0) return true;
        /*
        vector<int> jump;
        jump.push_back(0);
        int i = 1;
        for (; i < size; ++i) {
            int tmp = std::max(jump[i-1], A[i-1]) - 1;
            if (tmp < 0) {
                return false;
            }
            if (tmp == 0 && i < (size-1)){
                return false;
            }
            jump.push_back(tmp);
        }
        if (i==size-1) {
            return true;
        }
        */
        // greedy
        int maxCover = 0;
        for (int i = 0; i <= maxCover; ++i) {
            maxCover = std::max(maxCover, A[i]+i);
            if (maxCover >= (size-1)) {
                return true;
            }
        }
        return false;
    }
};
