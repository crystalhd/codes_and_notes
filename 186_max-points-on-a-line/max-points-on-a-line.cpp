/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/max-points-on-a-line
@Language: C++
@Datetime: 16-07-18 22:33
*/

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    /**
     * @param points an array of point
     * @return an integer
     */
    int maxPoints(vector<Point>& points) {
        // Write your code here
        int size = points.size();
        if (size <= 2) return size;
        std::unordered_map<double, int> record;
        int max = 0;
        for (int i = 0; i < size; ++i) {
            record.clear();
            Point p1 = points[i];
            int same = 1;
            for (int j = 0; j < size; ++j) {
                if (j==i) continue;
                Point p2 = points[j];
                if (p1.x == p2.x && p1.y == p2.y) {++same; continue;}
                if (p1.x == p2.x) {
                    if (record.find(INT_MAX) == record.end())
                    {
                        record[INT_MAX] = 1;
                    } else {
                        ++record[INT_MAX];
                    }
                } else {
                    double k = (double)(p1.y - p2.y)/(double)(p1.x - p2.x);
                    if (record.find(k) == record.end())
                    {
                        record[k] = 1;
                    } else {
                        ++record[k];
                    }
                }
            }
          //  std::cerr<<same<<" ";
          if(record.size() == 0) {
              max = max > same ? max : same;
          }
            for (auto i = record.begin(); i != record.end(); ++i) {
                std::cerr<<(i->second)<<" ";
                max = max > (i->second + same) ? max : (i->second + same) ;
            }
           
        }
        return max;
    }
};