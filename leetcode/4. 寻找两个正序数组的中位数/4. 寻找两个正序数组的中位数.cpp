//
// Created by 53110 on 2022/3/11.
//
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    //双指针
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int i = 0;
        int j = 0;
        int left = 0;
        int right = 0;


        for (int k = 0; k < (n + m) / 2 + 1; ++k) {
            if (i >= n){
                left = right;
                right = nums2[j++];
            } else if (j >= m){
                left = right;
                right = nums1[i++];
            } else{
                left = right;
                right = nums1[i] < nums2[j]?nums1[i++]:nums2[j++];
            }
        }
        return (m + n) & 1 ? right : (left + right) / 2.0;
    }
    //暴力递归
    double findMedianSortedArraysFib(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int i = 0;
        int j = 0;
        int k = 0;
        vector<int> nums(n + m);
        while(i < n && j < m){
            nums[k++] = nums1[i] < nums2[j]?nums1[i++]:nums2[j++];
        }
        while(i < n){
            nums[k++] = nums1[i++];
        }
        while (j < m){
            nums[k++] = nums2[j++];
        }
        return k & 1? nums[k / 2]: (double)(nums[k / 2 - 1] + nums[k / 2]) / 2;
    }

};

int main(){
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2, 7};
    double res = Solution().findMedianSortedArraysFib(nums1, nums2);
    cout<<res;
    return 0;
}