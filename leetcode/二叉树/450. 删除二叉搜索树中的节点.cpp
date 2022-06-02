//
// Created by 53110 on 2022/6/2.
//
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    // 此方法会增加树的高度
    TreeNode *deleteNode(TreeNode *root, int key) {
        if(root == nullptr) return nullptr;
        // 当前结点大于目标值， 那么向左子树寻找
        if(root->val > key) root->left = deleteNode(root->left, key);
        else if(root->val < key) root->right = deleteNode(root->right, key);
        // 当前结点即为要删除的结点
        else{
            // 如果不存在左子树，则右子树直接代替该节点
            if(root->left == nullptr) root = root->right;
            // 如果不存在右子树，则左子树直接代替该节点
            if(root->right == nullptr) root = root->left;
            // 如果左右子树均存在，则左子树放到右子树最左节点上
            TreeNode* temp = root->right;
            while(temp->left != nullptr){
                temp = temp->left;
            }
            temp->left = root->left;
            root = root->right;
        }
        return root;
    }
};