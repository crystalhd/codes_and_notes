/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/insert-interval
@Language: C++
@Datetime: 16-06-13 21:42
*/

/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */
class Solution {
public:
    /**
     * Insert newInterval into intervals.
     * @param intervals: Sorted interval list.
     * @param newInterval: new interval.
     * @return: A new interval list.
     */
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // write your code here
        int size = intervals.size();
        std::vector<Interval> result;
        if (size == 0) {
            result.push_back(newInterval);
            return result;
        }
        bool inserted = false;
        for (int i = 0; i < size; ++i) {
            if (inserted) {
                result.push_back(intervals[i]);
                continue;
            }
            if (newInterval.end < intervals[i].start) {
                result.push_back(newInterval);
                result.push_back(intervals[i]);
                inserted = true;
                continue;
            }
            if (newInterval.start > intervals[i].end) {
                result.push_back(intervals[i]);
                continue;
            }
            int start = newInterval.start <= intervals[i].start ? newInterval.start : intervals[i].start;
            int end = newInterval.end > intervals[i].end ? newInterval.end : intervals[i].end;
            newInterval = Interval(start, end);
            
        }
        if (!inserted) {
            result.push_back(newInterval);
        }
        return result;
    }
};