//
// Created by 53110 on 2022/6/7.
//
#include <vector>
#include <algorithm>
using namespace std;

class Solution875 {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPile = *max_element(piles.begin(), piles.end());
        if(h == piles.size()){
            int maxPile = *max_element(piles.begin(), piles.end());
            return maxPile;
        }
        // 溢出
        // int sum = accumulate(piles.begin(), piles.end(), 0);
        int left = 1;
        int right = maxPile;
        while(left < right){
            int hh = 0;
            int mid = left + (right - left) / 2;
            for(auto &pile:piles){
                if(pile <= mid){
                    ++hh;
                }
                else{
                    hh += pile % mid == 0? (pile / mid):(pile / mid + 1);
                }
            }
            if(hh <= h){
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        return left;
    }
};