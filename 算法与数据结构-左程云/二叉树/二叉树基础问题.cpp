//
// Created by 53110 on 2022/3/28.
//
#include<climits>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


/*套路*/
/*判断是否是平衡二叉树*/
//
class ReturnType {
public:
    bool isBalance;
    int height;

    ReturnType(bool isB, int hei) {
        isBalance = isB;
        height = hei;
    }
};
/*套路*/
/*判断是否是二叉搜索树*/
//
class ReturnBstInfo {
public:
    bool isBST;
    int minVal;
    int maxVal;

    ReturnBstInfo(bool isBst, int minv, int maxv) {
        isBST = isBst;
        minVal = minv;
        maxVal = maxv;
    }
};

/*套路*/
/*判断是否是满搜索树*/
//
class isFullInfo {
public:
    int height;
    int nodes;

    isFullInfo(int hei, int node) {
        height = hei;
        nodes = node;
    }
};

class BasicProbTree {
public:
    // 递归
    // 是否为二叉搜索树
    // 用中序遍历的方法，如果是升序，则必为二叉搜索树，否则不是
    int preValue = INT_MIN;

    bool CheckBstRecur(TreeNode *root) {
        if (root == nullptr) {
            return true;
        }
        bool isLeftBst = CheckBstRecur(root->left);
        if (!isLeftBst) {
            return false;
        }
        if (root->val < preValue) {
            return false;
        } else {
            preValue = root->val;
        }
        return CheckBstRecur(root->right);
    }

    // 遍历
    bool CheckBstNoRecur(TreeNode *root) {
        if(root->left == nullptr && root->right == nullptr) return true;
        long long preValue = (long long) INT_MIN - 1;
        stack<TreeNode *> stk;
        while (!stk.empty() || root != nullptr) {
            if (root != nullptr) {
                stk.push(root);
                root = root->left;
            } else {
                root = stk.top();
                if (root->val <= preValue) {
                    return false;
                } else {
                    preValue = root->val;
                }
                stk.pop();
                root = root->right;
            }
        }
        return true;
    }

    /*判断是否是完全二叉树*/
    /*按宽度遍历*/
    /*
     * 1. 任一节点有右节点无左节点，则不是
     *2. 在1.的条件下，如果遇到第一个左右孩子不双全的情况，则接下来遇到的所有节点必须为叶节点
    */
    bool isCBT(TreeNode *root) {
        // 是否遇到过左右两个孩子不双全的节点
        bool leaf = false;
        TreeNode *l = nullptr;
        TreeNode *r = nullptr;
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty()) {
            root = que.front();
            que.pop();
            l = root->left;
            r = root->right;
            // 如果遇到左右孩子不双全的节点后，又发现当前节点有孩子 则不是完全二叉树
            if ((leaf && (l != nullptr || r != nullptr)) || (l == nullptr && r != nullptr)) {
                return false;
            }
            if (l != nullptr) {
                que.push(l);
            }
            if (r != nullptr) {
                que.push(r);
            }
            if (l == nullptr || r == nullptr) {
                leaf = true;
            }
        }
        return true;
    }



    /*套路解法*/


    /*判断是否是平衡二叉树*/
    //
    ReturnType *process(TreeNode *root) {
        if (root == nullptr) {
            return new ReturnType(true, 0);
        }
        ReturnType *leftData = process(root->left);
        ReturnType *rightData = process(root->right);
        int height = max(leftData->height, rightData->height) + 1;
        bool isBacnced = leftData->isBalance && rightData->isBalance && abs(leftData->height - rightData->height) < 2;
        return new ReturnType(isBacnced, height);
    }

    /*判断是否是二叉s搜索树*/
    ReturnBstInfo *isBSTRoutine(TreeNode *root) {
        if (root == nullptr) {
            return nullptr;
        }
        ReturnBstInfo *leftData = isBSTRoutine(root->left);
        ReturnBstInfo *rightData = isBSTRoutine(root->right);
        int min1 = root->val;
        int max1 = root->val;
        if (leftData != nullptr) {
            min1 = min(min1, leftData->minVal);
            max1 = max(max1, leftData->maxVal);
        }
        if (rightData != nullptr) {
            min1 = min(min1, rightData->minVal);
            max1 = max(max1, rightData->maxVal);
        }
        bool isBst = true;
        if (leftData != nullptr && (!leftData->isBST || leftData->maxVal >= root->val)) {
            isBst = false;
        }
        if (rightData != nullptr && (!rightData->isBST || root->val >= rightData->minVal)) {
            isBst = false;
        }
        return new ReturnBstInfo(isBst, min1, max1);
    }


    /*判断是否是满二叉树*/
    // 节点数 = 2^l - 1
private:
    isFullInfo *isFullT(TreeNode *root) {
        if (root == nullptr) {
            return new isFullInfo(0, 0);
        }
        isFullInfo *leftData = isFullT(root->left);
        isFullInfo *rightData = isFullT(root->right);
        int height = max(leftData->height, rightData->height) + 1;
        int nodes = leftData->nodes + rightData->nodes + 1;

        return new isFullInfo(height, nodes);
    }

public:
    bool isFull(TreeNode *root) {
        if (root == nullptr) {
            return true;
        }
        isFullInfo *data = isFullT(root);
        return data->nodes == ((1 << data->height) - 1);
    }
};


