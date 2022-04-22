//
// Created by 53110 on 2022/4/22.
//

#include <vector>

using namespace std;
/*
 * 在一个二维数组中，每一行都按照从左到右递增的顺序排序，
 * 每一列都按照从上到下递增的顺序排序
 * 请完成一个函数，输入这样的一个二维数组和一个一维整数，判断数组中是否含有该整数
 * {{1, 2, 8, 9},\
 *  {2, 4, 9, 12},
 *  {4, 7, 10, 13},
 *  {6, 8, 11, 15}}
 * */
class Solution04_{
public:
    bool Find(vector<vector<int>> &matrix, int number){
        int rows = matrix.size();
        int cols = matrix[0].size();
        bool found = false;
        if (rows > 0 && cols > 0){
            int row = 0;
            int col = cols - 1;
            while (row < rows && col >= 0){
                if (matrix[row][col] == number){
                    found = true;
                    break;
                }
                else if (matrix[row][col] > number){
                    --col;
                }else{
                    --row;
                }
            }
        }
        return found;
    }
};

