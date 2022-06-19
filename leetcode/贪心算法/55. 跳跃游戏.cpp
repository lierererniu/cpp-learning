class Solution {
public:
    bool canJump(vector<int>& nums) {
        int _Size = nums.size();
        if(_Size == 1) return true;
        int cover = 0;
        // 在当前最大的覆盖范围内寻找是否还能跳到更远的位置
        for(int i = 0; i <= cover; ++i){
            // 求最大的覆盖范围，
            cover = max(i + nums[i], cover);
            if(cover >= _Size - 1) return true;
        }
        return false;
    }
};
