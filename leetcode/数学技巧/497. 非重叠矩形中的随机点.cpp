#include<vector>
#include <random>
using namespace std;

class Solution497{
public:
    vector<int> arr;
    vector<vector<int>> rects;
    int _size;
    Solution497(vector<vector<int>> &rect){
        this->rects = rect;
        this->_size = rect.size();
        // 初始化面积
        arr.push_back(0);
        for(auto & rec:rects){
            int l = rec[2] - rec[0] + 1;
            int h = rec[3] - rec[1] + 1;
            arr.push_back(arr.back() + h * l);
        }
    }
    vector<int> pick(){
        int num = rand() % arr.back() + 1;
        int left = 0, right = _size;
        // 二分查找选中的方块在哪个地区
        while (left < right){
            int mid = left + (right - left) / 2;
            if(arr[mid] >= num){
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        int x = rects[right - 1][2] - rects[right - 1][0];
        int y = rects[right - 1][3] - rects[right - 1][1];
        return {rand()%x + rects[right - 1][0], rand()%y + rects[right - 1][1]};
    }
};