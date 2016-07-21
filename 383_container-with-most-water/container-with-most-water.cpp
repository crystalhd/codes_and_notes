/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/container-with-most-water
@Language: C++
@Datetime: 16-07-20 20:33
*/

class Solution {
public:
    /**
     * @param heights: a vector of integers
     * @return: an integer
     */
    int maxArea(vector<int> &heights) {
        // write your code here
        int size = heights.size();
        if (size == 0 || size == 1) return 0;
        int max = 0;
        int start = 0;
        int end = size - 1;
        while (start < end) {
            int minHeight = heights[start] <= heights[end] ? heights[start] : heights[end];
            int tmpArea = minHeight * (end-start);
            max = max >= tmpArea ? max : tmpArea;
            int index1 = start+1; 
            int index2 = end-1;
            if (heights[start] <= heights[end])
            {
                while (heights[index1] <= heights[start]) {
                    ++index1;
                }
                start = index1;
            } 
            else {
                while(index2 > start && heights[index2] <= heights[end]) {
                    --index2;
                }
                end = index2;
            }
        }
        return max;
    }
};