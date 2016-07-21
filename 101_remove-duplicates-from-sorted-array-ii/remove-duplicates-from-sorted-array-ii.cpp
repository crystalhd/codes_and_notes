/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/remove-duplicates-from-sorted-array-ii
@Language: C++
@Datetime: 16-05-04 00:08
*/

class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        // write your code here
        int length = nums.size();
        if (length < 2) return length;
        
        int max = nums[length-1];
        
        int cur = 1;
        int size = 0;
        for (int i=1; i<nums.size(); ++i)
        {
            if (nums[i] == nums[size])
            {
                ++cur;
                if(cur <= 2)
                {
                    ++size;
                    nums[size] = nums[i];
                }
            }
            else
            {
                cur = 1;
                ++size;
                nums[size] = nums[i];
            }
            
            
        }
        return size+1;
    }
};