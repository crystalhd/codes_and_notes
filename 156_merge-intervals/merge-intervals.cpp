/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/merge-intervals
@Language: C++
@Datetime: 16-06-19 21:07
*/

/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
class Solution {
public:
    /**
     * @param intervals: interval list.
     * @return: A new interval list.
     */
    struct sortInterval {
        bool operator()(const Interval& i1, const Interval& i2) const {
            return i1.start < i2.start;
        }
    };
    vector<Interval> merge(vector<Interval> &intervals) {
        // write your code here
        int size = intervals.size();
        if (size == 0 || size == 1) {
            return intervals;
        }
        std::vector<Interval> result;
        sort(intervals.begin(), intervals.end(), sortInterval());
        Interval prev = intervals[0];
        for (int i = 1; i < size; ++i) {
            Interval cur = intervals[i];
            //Interval next = intervals[i+1];
            if (cur.start > prev.end) {
                result.push_back(prev);
                prev = cur;
                continue;
            }
            int newEnd = cur.end > prev.end ? cur.end : prev.end;
            prev = Interval(prev.start, newEnd);
        }
        result.push_back(prev);
        return result;
    }
};