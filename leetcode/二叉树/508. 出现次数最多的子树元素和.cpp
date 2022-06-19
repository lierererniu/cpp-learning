//
// Created by 53110 on 2022/6/19.
//

#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;


struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr){}
    TreeNode(int val): val(val), left(nullptr), right(nullptr){}
    TreeNode(int val, TreeNode* left, TreeNode* right): val(val), left(left), right(right){}
};

class Solution508{
public:
    // 暴力
    unordered_map<int,int> temp;
    int maxOcur = 0;
    vector<int> res;
//    vector<int> findFrequentTreeSum(TreeNode* root){
//        if(root == nullptr) return {};
//        TreeSum(root);
//        return res;
//    }
//    void TreeSum(TreeNode* root){
//        if(root == nullptr) return;
//        int sum = bfs(root);
//        temp[sum] ++;
//        if(temp[sum] > maxOcur){
//            maxOcur = temp[sum];
//            res = {sum};
//        }else if(temp[sum] == maxOcur){
//            res.push_back(sum);
//        }
//        TreeSum(root->left);
//        TreeSum(root->right);
//    }
//
//    int bfs(TreeNode* root){
//        queue<TreeNode *> que;
//        int temp = 0;
//        que.push(root);
//        while(!que.empty()){
//            int sz = que.size();
//            while(sz){
//                root = que.front();
//                temp += root->val;
//                if (root->left != nullptr) que.push(root->left);
//                if (root->right != nullptr) que.push(root->right);
//                que.pop();
//                sz --;
//            }
//        }
//        return temp;
//    }

    vector<int> findFrequentTreeSum1(TreeNode* root) {
        if(root == nullptr) return {};
        recur(root);
        return res;
    }

    int recur(TreeNode* root){
        if(root == nullptr) return 0;
        int cur = root->val + recur(root->left) + recur(root->right);
        temp[cur]++;
        if(temp[cur] > maxOcur){
            maxOcur = temp[cur];
            // 有更大的了，直接赋值  将之前的记录结果覆盖掉，重新计算
            res = {cur};
        }else if (temp[cur] == maxOcur){
            res.push_back(cur);
        }
    }
};
