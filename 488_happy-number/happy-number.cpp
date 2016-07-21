/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/happy-number
@Language: C++
@Datetime: 16-01-29 05:07
*/

class Solution {
public:
    /**
     * @param n an integer
     * @return true if this is a happy number or false
     */
    bool isHappy(int n) {
        // Write your code here
        // get the digits of number n:
        if (n==1)
            return true;
        
        vector<int> record;
        int result = 0;
        while(1)
        {
            result = sumDigits(n);
            if (result == 1)
                return true;
            else if (std::find(record.begin(), record.end(), result) != record.end())
                return false;
            else
            {
                record.push_back(result);
                n = result;
            }    
        }
        
    }
    int sumDigits(int num)
    {
        int result = 0;
        while(num>0)
        {
            int remain = num % 10;
            result += remain * remain;
            num = num / 10; 
            if (num == 1)
            {
                result += 1;
                break;
            }
        }
        return result;
    }
};