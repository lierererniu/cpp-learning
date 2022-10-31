//
// Created by 53110 on 2022/9/15.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution27{
public:
    int removeElement(vector<int>& nums, int val){
        // int fast = 0;
        int slow = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if(nums[i] != val){
                nums[slow++] = nums[i];
            }
        }
        return slow;
    }

};
int main(){
    vector<int> arr = {0,1,2,2,3,0,4,2};
    auto res = Solution27().removeElement(arr, 2);
    cout<<res<<endl;
    return 0;
}