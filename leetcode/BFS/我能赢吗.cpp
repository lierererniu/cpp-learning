//
// Created by 53110 on 2022/5/22.
//

#include <unordered_set>

using namespace std;

//class Solution {
//public:
//    来自【负雪明烛】图解算法：递归，步步优化，弄清每个细节 https://leetcode.cn/problems/can-i-win/solution/by-fuxuemingzhu-g16c/
//    bool canIWin(int maxChoosableInteger, int desiredTotal) {
//        // 候选集，「公共整数池」
//        unordered_set<int> choosable;
//        for (int i = 1; i <= maxChoosableInteger; ++i) {
//            choosable.insert(i);
//        }
//        // 判断当前做选择的玩家（先手），是否一定赢
//        return dfs(choosable, 0, maxChoosableInteger, desiredTotal);
//    }
//
//    // 当前做选择的玩家是否一定赢
//    bool dfs(unordered_set<int>& choosable, int sum, int maxChoosableInteger, int desiredTotal) {
//        // 遍历可选择的公共整数
//        for (int x : choosable) {
//            // 如果选择了 x 以后，大于等于了 desiredTotal，当前玩家赢
//            if (sum + x >= desiredTotal) {
//                return true;
//            }
//            // 改变「公共整数池」
//            // 为了避免影响当前的 choosable，因此复制了一份并擦出掉 x，传给对手
//            unordered_set<int> choosable_copy = choosable;
//            choosable_copy.erase(x);
//            // 当前玩家选择了 x 以后，判断对方玩家一定输吗？
//            if (!dfs(choosable_copy, sum + x, maxChoosableInteger, desiredTotal)) {
//                return true;
//            }
//        }
//        return false;
//    }
//
//};

class Solution464 {
private:
    // visited[i] == 0，说明没有计算过
    // visited[i] == 1，说明计算过，结果为 true
    // visited[i] == 2，说明计算过，结果为 false
    int visited[1 << 21];
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        // 最大选择比和大，先手必赢
        if(maxChoosableInteger >= desiredTotal) return true;
        // 最大选择大于 目标和 - 1， 先手必输
        if(maxChoosableInteger + 1 > desiredTotal) return false;
        // 判断当前做选择的玩家（先手），是否一定赢
        // 开始时，state = 0，表示「公共整数集」中的所有数字都未被使用过
        return dfs(0, 0, maxChoosableInteger, desiredTotal);
    }

    // 当前做选择的玩家是否一定赢
    bool dfs(int state, int sum, int maxChoosableInteger, int desiredTotal) {
        if (visited[state] == 1) return true;
        if (visited[state] == 2) return false;
        // 遍历可选择的公共整数
        for (int x = 1; x <= maxChoosableInteger; ++x) {
            // 如果 x 已经被使用过了，则不能选择
            if ((1 << x) & state) continue;
            // 如果选择了 x 以后，大于等于了 desiredTotal，当前玩家赢
            if (sum + x >= desiredTotal) {
                visited[state] = 1;
                return true;
            }
            // 当前玩家选择了 x 以后，判断对方玩家一定输吗？
            if (!dfs(((1 << x) | state), sum + x, maxChoosableInteger, desiredTotal)) {
                visited[state] = 1;
                return true;
            }
        }
        visited[state] = 2;
        return false;
    }

};
