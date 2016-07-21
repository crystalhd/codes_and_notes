/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/surrounded-regions
@Language: C++
@Datetime: 16-06-20 03:30
*/

class Solution {
public:
    /**
     * @param board a 2D board containing 'X' and 'O'
     * @return void
     */
    void surroundedRegions(vector<vector<char>>& board) {
        // Write your code here
        int height = board.size();
        if (height == 0) return;
        int width = board[0].size();
        if (width == 0) return;
        for (int i = 0; i < width; ++i) {
            if (board[0][i] == 'O') {
                bfs(board, height, width, 0, i);
            }
            if (board[height-1][i] == 'O') {
                bfs(board, height, width, height-1, i);
            }
        }
        for (int i = 1; i < height-1; ++i) {
            if (board[i][0] == 'O') {
                bfs(board, height, width, i, 0);
            }
            if (board[i][width-1] == 'O') {
                bfs(board, height, width, i, width-1);
            }
        }
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                std::cerr<<board[i][j]<<" ";
            }
            std::cerr<<"\n";
        }
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                else if (board[i][j] == 'Y') {
                    board[i][j] = 'O';
                }
            }
        }
        return;
    }
    void bfs(vector<vector<char>>& board, int height, int width, int i, int j) {
        if (i<0 || j<0 || i>= height || j >= width) return;
        if (board[i][j] != 'O') return;
        std::cerr<<i<<" "<<j<<"\n";
        board[i][j] = 'Y';
        bfs(board, height, width, i+1, j);
        bfs(board, height, width, i-1, j);
        bfs(board, height, width, i, j+1);
        bfs(board, height, width, i, j-1);
    }
};