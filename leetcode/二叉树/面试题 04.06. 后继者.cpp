//
// Created by 53110 on 2022/5/16.
//
#include <stack>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution046{
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p){
        if(root == nullptr) return nullptr;
        stack<TreeNode*> stk;
        TreeNode* prev = nullptr;
        while(!stk.empty() || root != nullptr){
            while(root != nullptr){
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            if(prev == p){
                return root;
            }
            prev = root;
            root = root->right;
        }
        return nullptr;
    }
};