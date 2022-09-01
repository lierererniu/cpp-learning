//
// Created by 53110 on 2022/8/31.
//

#include <vector>
#include <string>
#include <iostream>
using namespace std;
/* 题目
 * https://leetcode.cn/problems/sudoku-solver/
 * */
class Solution37{
private:
    bool isVaild(vector<vector<char>>& board, int row, int col, char num){
        // 列
        for(int i = 0; i < board.size(); ++i){
            if(board[i][col] == num) return false;
        }
        for (int i = 0; i < board[0].size(); ++i) {
            if(board[row][i] == num) return false;
        }
        int x = row / 3;
        int y = col / 3;
        for (int i = 3 * x; i < 3 * x + 3; ++i) {
            for (int j = 3 * y; j < 3 * y + 3; ++j) {
                if(board[i][j] == num) return false;
            }
        }
        return true;
    }
    bool backtracking(vector<vector<char>>& board){
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if(board[i][j] != '.') continue;
                for (char num = '1'; num <= '9'; ++num) {
                    if (isVaild(board, i, j, num)){
                        board[i][j] = num;
                        if(backtracking(board)) return true;
                        board[i][j] = '.';
                    }
                }
                return false; // 如果这个位置什么数都不适合
            }
        }
        return true;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        backtracking(board);
    }
};

int main(){
    vector<vector<char>> board = {{'5','3','.','.','7','.','.','.','.'},
                                  {'6','.','.','1','9','5','.','.','.'},
                                  {'.','9','8','.','.','.','.','6','.'},
                                  {'8','.','.','.','6','.','.','.','3'},
                                  {'4','.','.','8','.','3','.','.','1'},
                                  {'7','.','.','.','2','.','.','.','6'},
                                  {'.','6','.','.','.','.','2','8','.'},
                                  {'.','.','.','4','1','9','.','.','5'},
                                  {'.','.','.','.','8','.','.','7','9'}};
    Solution37().solveSudoku(board);
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[0].size(); ++j) {
            cout<<board[i][j];
        }
        cout<<endl;
    }
    return 0;
}