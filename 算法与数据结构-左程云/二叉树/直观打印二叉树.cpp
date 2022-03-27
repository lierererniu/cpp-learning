//
// Created by 53110 on 2022/3/27.
//
#include <string>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class SolutionPrintTree {
public:
    void mPrint(TreeNode *head) {
        cout << "Binary Tree:" << endl;
        printInOrder(head, 0, "H", 17);
        cout << endl;
    }

    void printInOrder(TreeNode *head, int height, string to, int len) {
        if (head == nullptr) {
            return;
        }
        // 先打印右子树
        printInOrder(head->right, height + 1, "v", len);
        // 打印根节点
        string val = to + to_string(head->val) + to;
        int lenM = val.size();
        int lenL = (len - lenM) / 2;
        int lenR = len - lenM - lenL;
        val = string(lenL, ' ') + val + string(lenR, ' ');
        cout << string(height * len, ' ') << val << endl;
        printInOrder(head->left, height + 1, "^", len);
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
    SolutionPrintTree().mPrint(head);
    return 0;
}