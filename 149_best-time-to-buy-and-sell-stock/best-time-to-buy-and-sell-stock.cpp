/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/best-time-to-buy-and-sell-stock
@Language: C++
@Datetime: 16-07-19 23:40
*/

class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        
        int size = prices.size();
        if (size <= 1) return 0;
        int max = 0;
        int min = INT_MAX;
        for (int i = 0; i < size; ++i) {
            min = min <= prices[i] ? min : prices[i];
            if (prices[i] < min) {
                min = prices[i];
            } else {
                int tmp = prices[i] - min;
                max = max >= tmp ? max : tmp;
            }
        }
        return max;
    }
};
