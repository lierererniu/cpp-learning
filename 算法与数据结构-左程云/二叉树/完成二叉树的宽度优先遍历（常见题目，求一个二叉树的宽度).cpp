//
// Created by 53110 on 2022/3/27.
//
#include <queue>
#include <iostream>
#include <map>
#include<limits.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr){}
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right){}
};
// 队列 求最大宽度
class PreWidthOrder{
public:
    // 哈希表
    int WidthOrder(TreeNode *root){
        if (root == nullptr){
            return 0;
        }
        //
        map<TreeNode *, int> levelMap;
        levelMap[root] = 1;
        // 记录当前层
        int curLevel = 1;
        int curLevelNodes = 0;
        int maxW = INT_MIN;

        queue<TreeNode *> que;
        que.push(root);
        while(!que.empty()){
            TreeNode *cur = que.front();
            que.pop();
            int curNodeLevel = levelMap[cur];
            // 层数没变，该层节点数 + 1
            if(curNodeLevel == curLevel){
                curLevelNodes ++;
            }else{
                maxW = max(maxW, curLevelNodes);
                curLevel++;
                curLevelNodes = 1;
            }
            if (cur->left != nullptr){
                levelMap[cur->left] = curNodeLevel + 1;
                que.push(cur->left);
            }
            if (cur->right != nullptr){
                levelMap[cur->right] = curNodeLevel + 1;
                que.push(cur->right);
            }
        }
        return maxW;
    }
    // 非哈希表方法
    int WidthOrderNoMap(TreeNode *root){

    }
};
// 求最大深度
class depth{
public:
    // 广度优先搜索
    int maxdepth(TreeNode *root){
        if(root == nullptr){
            return 0;
        }
        int res = 0;
        queue<TreeNode *> que;
        que.push(root);
        while(!que.empty()){
            int sz = que.size();
            while(sz){
                root = que.front();
                if (root->left != nullptr) que.push(root->left);
                if (root->right != nullptr) que.push(root->right);
                que.pop();
                sz --;
            }
            res ++;
        }
        return res;
    }
    // 深度优先搜索
    int priDepth(TreeNode *root){
        if (root == nullptr){
            return 0;
        }
        return max(priDepth(root->left), priDepth(root->right)) + 1;
    }

};

int main() {
    TreeNode *head = new TreeNode(5);
    head->left = new TreeNode(3);
    head->right = new TreeNode(8);
    head->left->left = new TreeNode(2);
    head->left->right = new TreeNode(4);
    head->left->left->left = new TreeNode(1);
    head->right->left = new TreeNode(7);
    head->right->left->left = new TreeNode(6);
    head->right->right = new TreeNode(10);
    head->right->right->left = new TreeNode(9);
    head->right->right->right = new TreeNode(11);
    int res = PreWidthOrder().WidthOrder(head);
    int height = depth().maxdepth(head);
    int heighr = depth().priDepth(head);
    cout << res << endl;
    cout << height << endl;
    cout << heighr << endl;
    return 0;
}