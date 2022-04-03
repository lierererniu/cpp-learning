//
// Created by 53110 on 2022/3/29.
//

//o1 和o2一定属于root为头的树
// 返回o1和o2的最低公共祖先
#include<climits>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class LAC{
public:
    // 非哈希 递归
    TreeNode *LowestAncestor(TreeNode *root, TreeNode *o1, TreeNode *o2){
        if (root == nullptr || root == o1 || root == o2){
            return root;
        }
        TreeNode *left = LowestAncestor(root->left, o1, o2);
        TreeNode *right = LowestAncestor(root->right, o1, o2);
        if (left != nullptr && right != nullptr){
            return root;
        }
        return left != nullptr ? left : right;
    }
};