/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/min-stack
@Language: C++
@Datetime: 16-07-18 18:31
*/

class MinStack {
public:
    MinStack() {
        // do initialization if necessary
    }

    void push(int number) {
        // write your code here
       stack_.push(number);
       if (min_.size() == 0 || number <= min_.top()) {
           min_.push(number);
       }
    }

    int pop() {
        // write your code here
        if (stack_.size() == 0) return 0;
        int top = stack_.top();
        stack_.pop();
        if (top == min_.top()) {
            min_.pop();
        }
        return top;
    }

    int min() {
        // write your code here
        return min_.top();  
    }
private:
    std::stack<int> stack_;
    std::stack<int> min_;
};
