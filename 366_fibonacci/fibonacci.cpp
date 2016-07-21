/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/fibonacci
@Language: C++
@Datetime: 16-01-28 17:18
*/

class Solution{
public:
    /**
     * @param n: an integer
     * @return an integer f(n)
     */
    int fibonacci(int n) {
        // write your code here
        
        if (n==0 || n==1)
            return 0;
        if (n==2)
            return 1;
        int prepre = 0; //n==1
        int pre = 1; // n==2
        int current;
        int i=3; // n==3
        while(i<=n)
        {
            current = pre + prepre;
            prepre = pre;
            pre = current;
            ++i;
        }
        return current;
    }
};
