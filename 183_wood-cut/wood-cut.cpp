/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/wood-cut
@Language: C++
@Datetime: 16-07-10 05:07
*/

class Solution {
public:
    /** 
     *@param L: Given n pieces of wood with length L[i]
     *@param k: An integer
     *return: The maximum length of the small pieces.
     */
    int woodCut(vector<int> L, int k) {
        // write your code here
        int size = L.size();
        if (size == 0 || k <=0) return 0;
        if (size == 1 || k == 1) return L[0];
        std::sort(L.begin(), L.end());
        int start = 1;
        int end = L[size-1];
        int result = 0;
        while (start <= end) {
            int mid = start + (end-start)/2;
            std::cerr<<mid<<" ";
            if (calculate(L, mid) >= k) {
                start = mid + 1;
            } else if (calculate(L, mid) < k) {
                end = mid - 1;
            }
        }
        return end;
       
    }
    int calculate(vector<int> L, int m) {
        int sum = 0;
        for (int i = 0; i < L.size(); ++i) {
            sum += (L[i]/m);
        }
        return sum;
    }
};