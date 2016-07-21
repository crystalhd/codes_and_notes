/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/valid-sudoku
@Language: C++
@Datetime: 16-07-18 18:05
*/

class Solution {
public:
    /**
      * @param board: the board
      * @return: wether the Sudoku is valid
      */
    bool isValidSudoku(const vector<vector<char>>& board) {
        if (board.size()!=9 )
            return false;
        if (board[0].size()!=9)
            return false;
        std::set<int> record;
        // each row
        for (int i = 0; i < 9; ++i) {
            record.clear();
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    continue;
                } else {
                    if (record.find(board[i][j]) != record.end()) return false;
                    record.insert(board[i][j]);
                }
            }
        }
        // check each column
        for (int i = 0; i < 9; ++i) {
            record.clear();
            for (int j = 0; j < 9; ++j) {
                if (board[j][i] == '.') {
                    continue;
                } else {
                    if (record.find(board[j][i]) != record.end()) return false;
                    record.insert(board[j][i]);
                }
            }
        }
        // check each block
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                int row = i*3;
                int col = j*3;
                record.clear();
                for (int p = row; p<row+3; ++p) {
                    for (int q = col; q < col+3; ++q) {
                        if (board[p][q] == '.') {
                            continue;
                        } else {
                            if (record.find(board[p][q]) != record.end()) return false;
                            record.insert(board[p][q]);
                        }
                    }
                }
                
            }
        }
        return true;
    }
};