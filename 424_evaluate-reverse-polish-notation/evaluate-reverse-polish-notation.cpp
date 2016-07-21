/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/evaluate-reverse-polish-notation
@Language: C++
@Datetime: 16-07-20 21:16
*/

class Solution {
public:
    /**
     * @param tokens The Reverse Polish Notation
     * @return the value
     */
    int evalRPN(vector<string>& tokens) {
        // Write your code here
        int size = tokens.size();
        if (size == 0) return 0;
        if (isOperator(tokens[0])) {
            return 0;
        }
        if (size == 1) {
            return std::stoi(tokens[0]);
        }
        std::stack<int> record;
        record.push(stoi(tokens[0]));
        int i = 1;
        while(i<size) {
            if (!isOperator(tokens[i])) {
                record.push(stoi(tokens[i]));
            } else {
                if (record.size() < 2) return 0;
                int operand1 = record.top();
                record.pop();
                int operand2 = record.top();
                record.pop();
                if (tokens[i] == "+") {
                    record.push(operand1 + operand2);
                } else if (tokens[i] == "-") {
                    record.push(operand2 - operand1);
                } else if (tokens[i] == "*") {
                    record.push(operand2 * operand1);
                } else {
                    record.push(operand2 / operand1);
                }
            }
            ++i;
        }
        return record.top();
    }
    bool isOperator(string s) {
        if (s == "+" || s == "-" || s == "*" || s == "/") {
            return true;
        }
        return false;
    }
};