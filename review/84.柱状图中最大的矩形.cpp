//
// Created by 53110 on 2022/9/15.
//

#include <queue>
#include <iostream>
#include <stack>
using namespace std;

class Solution84{
public:
    // 维护左侧最小元素位置 栈底元素为左侧最小值
    // 第二次遍历 从右往左遍历计算 , 分别记录与最矮的组成的面积
    int largestRectangleArea(vector<int> &heights){
        int _size = heights.size();
        if(_size == 1) return heights[0];
        int res = -1;
        stack<int> stk;

        for (int i = 0; i < _size; ++i) {
            // 当右侧元素小于栈顶时， 更新此时的最大面积
            // 就是当出现非递增元素时， 计算此时能组成的最大面积， 维护栈内元素从栈底到栈底是递增出现的

            while(!stk.empty() && heights[stk.top()] > heights[i]){
                int length = heights[stk.top()];
                stk.pop();
                int weight = i;
                //
                if (!stk.empty()) {
                    weight = i - stk.top() - 1; // 两个较矮的之间的距离
                }
                cout<<length<< " "<< weight<<endl;
                res = max(res, length * weight);
            }
            stk.push(i);
        }
        // 计算从尾到头的递减序列可以围成的面积
        while(!stk.empty()){
            int length = heights[stk.top()];
            stk.pop();
            int weight = _size;  // 当栈内无元素时， 此时的面积就是_size * 栈内最矮的元素
            if(!stk.empty()){
                weight = _size - stk.top() - 1;  // 从后往前算，
            }
            cout<<length<< " "<< weight<<endl;
            res = max(res, length * weight);
        }
        return res;
    }

};

int main(){
    vector<int> arr = {2,1,5,6,2,3};
    cout<<Solution84().largestRectangleArea(arr);
    return 0;
}