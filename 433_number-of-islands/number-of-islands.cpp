/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/number-of-islands
@Language: C++
@Datetime: 16-06-20 02:29
*/

class Solution {
public:
    /**
     * @param grid a boolean 2D matrix
     * @return an integer
     */
    int numIslands(vector<vector<bool>>& grid) {
        // Write your code here
        int height = grid.size();
        if (height == 0) {
            return 0;
        }
        int width = grid[0].size();
        if (width == 0) return 0;
        int count = 0;
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (grid[i][j] == false) continue;
                std::cerr<<"new: "<<i<<" "<<j<<"\n";
                ++count;
                mark(grid, height, width, i,j);
            }
        }
        return count;
    }
    void mark(vector<vector<bool>>& grid, int height, int width, int x, int y) {
        if (x>=height || y>=width || x<0 || y<0) return;
        if (grid[x][y] == false) return;
        grid[x][y] = false;
        mark(grid, height, width,x, y+1);
        mark(grid, height, width,x+1, y);
        mark(grid, height, width,x, y-1);
        mark(grid, height, width,x-1, y);
        return;
    }
};