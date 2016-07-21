/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/two-sum
@Language: C++
@Datetime: 16-06-03 02:23
*/

class Solution {
public:
    /*
     * @param numbers : An array of Integer
     * @param target : target = numbers[index1] + numbers[index2]
     * @return : [index1+1, index2+1] (index1 < index2)
     */
     struct Node {
         int val_;
         int ind_;
         Node(int value, int index) : val_(value), ind_(index) {}
         bool operator<(const Node& node1) const
         {
             return val_ < node1.val_;
         }
     };
    vector<int> twoSum(vector<int> &nums, int target) {
        // write your code here
        // use hashmap
        /*vector<int> result(2, 0);
        std::unordered_map<int, int> record;
        for (int i = 0; i < nums.size(); ++i) {
            int p = target - nums[i];
            if (record.find(p) != record.end())
            {
                int index1 = i + 1;
                int index2 = record[p];
                result[0] = index1 < index2 ? index1 : index2;
                result[1] = index2 < index1 ? index1 : index2;
                return result;
            }
            record[nums[i]] = i + 1;
        }*/
        std::vector<int> result;
        std::vector<Node> record;
        for (int i = 0; i < nums.size(); ++i) {
            record.push_back(Node(nums[i], i+1));
        }
        std::sort(record.begin(), record.end());
        int start = 0;
        int end = record.size()-1;
        while(start <= end) {
            if (record[start].val_ + record[end].val_ > target) {
                --end;
            }
            else if (record[start].val_ + record[end].val_ < target) {
            
                ++start;
            }
            else {
                int index1 = record[start].ind_ < record[end].ind_ ? record[start].ind_ : record[end].ind_;
                int index2 = record[end].ind_ < record[start].ind_ ? record[start].ind_ : record[end].ind_;
                result.push_back(index1);
                result.push_back(index2);
                break;
            }
        }
        return result;
        
    }
};
