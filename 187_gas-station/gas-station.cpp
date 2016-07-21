/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/gas-station
@Language: C++
@Datetime: 16-07-15 20:04
*/

class Solution {
public:
    /**
     * @param gas: a vector of integers
     * @param cost: a vector of integers
     * @return: an integer 
     */
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        // write your code here
        int size = gas.size();
        if (size == 0) return 0;
        for (int i = 0; i < size; ++i) {
            if (cost[i] > gas[i]) {
                continue;
            }
            int start = i;
            int costTotal = 0;
            int gasTotal = 0;
            do {
                costTotal += cost[i];
                gasTotal += gas[i];
                if (costTotal > gasTotal) {
                    break;
                } else {
                    if (i == (size - 1)) {
                        i = 0;
                    } else {
                        ++i;
                    }
                }
            } while (i != start);
            if (i == start) {
                return i;
            } else {
                i = start;
            }
        }
        return -1;
    }
};