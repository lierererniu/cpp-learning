//
// Created by 53110 on 2022/3/6.
//
#include <algorithm>
#include <vector>
#include <iostream>


using namespace std;

class Solution1648 {
public:
    int maxProfit(vector<int> &inventory, int orders) {
        long res = 0, mod = 1e9 + 7;
        sort(inventory.begin(), inventory.end());
        int curIndex = inventory.size() - 1;
        int curValue = inventory[curIndex];
        while (orders > 0) {
            while (curIndex >= 0 && inventory[curIndex] == curValue) {
                curIndex -= 1;
            }
            int nextValue = curIndex < 0 ? 0 : inventory[curIndex];
            int numsSameColor = inventory.size() - 1 - curIndex;
            int nums = (curValue - nextValue) * numsSameColor;
            if (orders > nums) {
                res += (long) (curValue + nextValue + 1) * (curValue - nextValue) / 2 * numsSameColor;
            } else {
                int numFullRow = orders / numsSameColor;
                int remainder = orders % numsSameColor;
                res += (long) (curValue + curValue - numFullRow + 1) * numFullRow / 2 * numsSameColor;
                res += (long) (curValue - numFullRow) * remainder;
            }
            orders -= nums;
            res = res % mod;
            curValue = nextValue;
        }
        return res;
    }

};

int main() {
    vector<int> inventory = {2, 8, 4, 10, 6};
    int orders = 20;
    int profit = Solution1648().maxProfit(inventory, orders);
    cout << "ÀûÈóÎª£º" << profit << endl;
}