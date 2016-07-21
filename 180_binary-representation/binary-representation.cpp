/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/binary-representation
@Language: C++
@Datetime: 16-07-11 06:46
*/

class Solution {
public:
    /**
     *@param n: Given a decimal number that is passed in as a string
     *@return: A string
     */
    string binaryRepresentation(string n) {
        // wirte your code here
        int size = n.size();
        if (size == 0) return n;
        int decPoint = n.find('.');
        int intPart;
        double decPart;
        if (decPoint == std::string::npos) {
            intPart = std::stoi(n);
            decPart = 0.0;
        } else {
            intPart = atoi(n.substr(0, decPoint).c_str());
            //intPart = atoi(n.substr(0, n.find(".")).c_str());
           decPart = atof(n.substr(decPoint).c_str());
           // decPart = std::stof(n.substr(decPoint));
            //atof(n.substr(n.find("."),n.size() - n.find(".")).c_str());
            string tmp = "0" + n.substr(decPoint);
            //std::cerr<<tmp<<" ";
        }
        //std::cerr<<intPart<<" "<<decPart<<" ";
        string intString = "";
        string decString = "";
        if (intPart == 0) {
            intString = "0";
        }
        while (intPart > 0) {
            int tmp = intPart % 2;
            intString = to_string(tmp) + intString;
            intPart = intPart / 2;
        }
        if (decPart == 0.0) {
            return intString;
        }
        std::unordered_map<double, int> record;
        while (decPart > 0.0) {
            if (decString.size() > 32 || record.find(decPart) != record.end()) {
                return "ERROR";
            }
            record[decPart] = 1;
            //std::cerr<<decPart<<" ";
            double tmp = decPart * 2;
            if (tmp >= 1.0) {
                decString = decString + "1";
                decPart = tmp - 1.0;
            } else {
                decString = decString + "0";
                decPart = tmp;
            }
            
        }
       
        return intString + "." + decString;
        
    }
};
