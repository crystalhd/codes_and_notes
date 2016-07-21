/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/majority-number-iii
@Language: C++
@Datetime: 16-06-02 03:59
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: As described
     * @return: The majority number
     */
    struct Candidate {
        int val;
        int cnt;
        Candidate(int value, int count) : val(value), cnt(count) {}
        Candidate() = default;
    };
    int majorityNumber(vector<int> nums, int k) {
        // write your code here
       std::vector<Candidate> record(k-1, Candidate());
       for (int i = 0; i < nums.size(); ++i) {
           int j = 0;
           for (j; j < k-1; ++j)
           {
               if (record[j].val == nums[i]) {
                   ++record[j].cnt;
                   break;
               }
           }
           if (j == k-1) {
               int m = 0;
               for (; m < k - 1; ++m) {
                   if (record[m].cnt == 0) {
                       record[m].val = nums[i];
                       record[m].cnt = 1;
                       break;
                   }
                   
               }
               if (m == k - 1) {
                   for (int n = 0; n < k - 1; ++n)
                   {
                       --record[n].cnt;
                   }
               }
           }
       }
       std::vector<int> numCount(k - 1, 0);
       for (int i = 0; i < nums.size(); ++i) {
           for (int j = 0; j < k - 1; ++j) {
               if (record[j].val == nums[i]) {
                   ++numCount[j];
               }
               if (numCount[j] > nums.size() / k)
               {
                   return record[j].val;
               }
           }
       }
       return -1;
    }
};
