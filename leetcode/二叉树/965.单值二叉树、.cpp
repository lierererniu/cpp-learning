//
// Created by 53110 on 2022/5/24.
//

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution965{
public:
    bool isUnivalTree(TreeNode* root) {
        if(root->left == nullptr && root->right == nullptr) return true;
        return bfs(root->val, root);
    }

    bool bfs(int val, TreeNode* root){
        if(root == nullptr) return true;
        if(val != root->val) return false;
        return bfs(val, root->left) && bfs(val, root->right);
    }
};