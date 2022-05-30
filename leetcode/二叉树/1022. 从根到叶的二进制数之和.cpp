//
// Created by 53110 on 2022/5/30.
//
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution1022 {
public:
    // 层序遍历
    int sumRootToLeaf(TreeNode* root) {
        if(root->left == nullptr && root->right == nullptr) return root->val;
        queue<TreeNode*> que;
        que.push(root);
        int res = 0;
        while(!que.empty()){
            int N = que.size();
            for(int i = 0; i < N; ++i){
                TreeNode* root = que.front();
                que.pop();
                if(root->left != nullptr){
                    root->left->val += root->val << 1;
                    que.push(root->left);
                }
                if(root->right != nullptr){
                    root->right->val += root->val << 1;
                    que.push(root->right);
                }
                if(root->left == nullptr && root->right == nullptr){
                    res += root->val;
                }
            }
        }
        return res;
    }
    // 递归
    int sumRootToLeaf_recur(TreeNode* root) {
        recur(root, 0);
        return res_recur;
    }
    void recur(TreeNode* root, int val){
        if (root == nullptr) return;
        val = (val << 1) + root->val;
        if(root->left == nullptr && root->right == nullptr){
            res_recur += val;
        }
        recur(root->left, val);
        recur(root->right, val);
    }

private:
    int res_recur = 0;

};