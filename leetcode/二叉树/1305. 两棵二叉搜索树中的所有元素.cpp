//
// Created by 53110 on 2022/5/2.
//

#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr){}
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right){}
};

class Solution1305{
public:
    // 暴力解法，两个中序遍历，然后再排序
    vector<int> res_;
    void recur(TreeNode* root){
        if(root == nullptr){
            return;
        }
        if(root->left != nullptr){
            recur(root->left);
        }
        res_.push_back(root->val);
        if(root->right != nullptr){
            recur(root->right);
        }
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        if(root1 != nullptr){
            recur(root1);
        }
        if(root2 != nullptr){
            recur(root2);
        }
        sort(res_.begin(), res_.end());
        return res_;
    }

    void recur(TreeNode* root, vector<int> &res){
        if(root == nullptr){
            return;
        }
        if(root->left != nullptr){
            recur(root->left, res);
        }
        res.push_back(root->val);
        if(root->right != nullptr){
            recur(root->right, res);
        }
    }
    vector<int> merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        /* 定义双指针 */
        int p1 = m - 1, p2 = n - 1;
        /* 定义尾指针 */
        int tail = m + n - 1;
        /* 扩展数组大小 */
        nums1.resize(m + n);
        while(p1 >= 0 || p2 >= 0) {
            if(p1 == -1) nums1[tail--] = nums2[p2--];
            else if (p2 == -1) nums1[tail--] = nums1[p1--];
            else if (nums1[p1] > nums2[p2]) nums1[tail--] = nums1[p1--];
            else nums1[tail--] = nums2[p2--];
        }
        return nums1;
    }
    vector<int> getAllElements1(TreeNode* root1, TreeNode* root2) {
        vector<int> nums1;
        vector<int> nums2;
        if(root1 != nullptr){
            recur(root1, nums1);
        }
        if(root2 != nullptr){
            recur(root2, nums2);
        }
        vector<int> res1(nums1.size() + nums2.size());
        res1 = merge(nums1, nums1.size(), nums2, nums2.size());
        return res1;
    }


};

// https://leetcode-cn.com/u/affectionate-joliotnee/
class Solution1305_ {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> result; //存放最后数据
        stack<TreeNode*> stTree1, stTree2; //使用两个stack容器进行root1和root2的数据存放
        TreeNode* Tree1 = root1, * Tree2 = root2; //使用两个指针分别进行两棵树的遍历
        while (Tree1 || Tree2 || !stTree1.empty() || !stTree2.empty()) {
            //先找到root1的最左端结点，以便于进行中序遍历
            while (Tree1) {
                stTree1.push(Tree1);
                Tree1 = Tree1->left;
            }
            //先找到root2的最左端结点，以便于进行中序遍历
            while (Tree2) {
                stTree2.push(Tree2);
                Tree2 = Tree2->left;
            }
            //进行中序遍历的过程中进行判断放值
            if (!stTree1.empty() && !stTree2.empty()) { //两个栈容器均不为空，取出值进行比较
                Tree1 = stTree1.top();
                Tree2 = stTree2.top();
                if (Tree1->val < Tree2->val) {
                    result.emplace_back(Tree1->val);
                    stTree1.pop();
                    Tree1 = Tree1->right;  //指向右孩子结点
                    Tree2 = nullptr;       //赋值为nullptr是为了防止下一轮循环继续压入左孩子结点，每一次压入一次进行数值处理
                } else {
                    result.emplace_back(Tree2->val);
                    stTree2.pop();
                    Tree2 = Tree2->right;  //指向右孩子结点
                    Tree1 = nullptr;       //赋值为nullptr是为了防止下一轮循环继续压入左孩子结点，每一次压入一次进行数值处理
                }
            } else if (stTree2.empty()){ //堆栈2为空，说明root2已经遍历结束
                Tree1 = stTree1.top();
                stTree1.pop();
                result.emplace_back(Tree1->val);
                Tree1 = Tree1->right;
            } else if (stTree1.empty()) {//堆栈1为空，说明root1已经遍历结束
                Tree2 = stTree2.top();
                stTree2.pop();
                result.emplace_back(Tree2->val);
                Tree2 = Tree2->right;
            }
        }
        return result;
    }
};
