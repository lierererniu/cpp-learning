//
// Created by 53110 on 2022/3/27.
//
#include <stack>
#include <iostream>
using namespace std;

struct tree{
    int val;
    tree *left;
    tree *right;
    tree(): val(0), left(nullptr), right(nullptr) {}
    tree(int x): val(x), left(nullptr), right(nullptr) {}
    tree(int x, tree *left, tree *right): val(x), left(left), right(right) {}
};

// 递归序

class ergodicFib{
public:
    // 二叉树递归序
    void fib(tree *head){
        if(head == nullptr){
            return;
        }
        fib(head->left);
        fib(head->right);
    }

    //先序遍历
    void preOrderRecur(tree *head){
        if(head == nullptr){
            return;
        }
        cout<< head->val << " ";
        preOrderRecur(head->left);
        preOrderRecur(head->right);
    }
    //中序遍历
    void InOrderRecur(tree *head){
        if(head == nullptr){
            return;
        }
        InOrderRecur(head->left);
        cout<< head->val << " ";
        InOrderRecur(head->right);
    }
    //后序遍历
    void PosOrderRecur(tree *head){
        if(head == nullptr){
            return;
        }
        PosOrderRecur(head->left);
        PosOrderRecur(head->right);
        cout<< head->val << " ";
    }

};

class ergodicNorm{
public:
    //先序遍历
    void preOrderUnRecur(tree *head){
        if (head != nullptr){
            stack<tree*> stk;
            stk.push(head);
            while(!stk.empty()){
                head = stk.top();
                cout<< head->val << " ";
                stk.pop();
                if (head->right != nullptr){
                    stk.push(head->right);
                }
                if (head->left != nullptr){
                    stk.push(head->left);
                }
            }
        }
        cout << endl;
    }
    //中序遍历
    void InOrderUnRecur(tree *head){
        if (head != nullptr){
            stack<tree *> stk;
            while (!stk.empty() || head != nullptr){
                if (head != nullptr){
                    stk.push(head);
                    head = head->left;
                }else{
                    head = stk.top();
                    cout<< head->val << " ";
                    stk.pop();
                    head = head->right;
                }
            }
        }
        cout << endl;
    }
    //后序遍历
    void PosOrderUnRecur(tree *head){
        if (head != nullptr){
            stack<tree *> stk1;
            stack<tree *> stk2;
            tree *temp = nullptr;
            stk1.push(head);
            while(!stk1.empty()){
                head = stk1.top();
                stk2.push(head);
                stk1.pop();
                if (head->left != nullptr){
                    stk1.push(head->left);
                }
                if (head->right != nullptr){
                    stk1.push(head->right);
                }
            }
            while(!stk2.empty()){
                temp = stk2.top();
                cout<< temp->val << " ";
                stk2.pop();
            }
            cout << endl;
        }
    }
};

int main(){
    tree *head = new tree(5);
    head->left = new tree(3);
    head->right = new tree(8);
    head->left->left = new tree(2);
    head->left->right = new tree(4);
    head->left->left->left = new tree(1);
    head->right->left = new tree(7);
    head->right->left->left = new tree(6);
    head->right->right = new tree(10);
    head->right->right->left = new tree(9);
    head->right->right->right = new tree(11);
    // 前序遍历
    cout << "前序遍历为："<<endl;
    ergodicFib().preOrderRecur(head);
    cout << endl;
    ergodicNorm().preOrderUnRecur(head);
    // 中序遍历
    cout << "中序遍历为："<<endl;
    ergodicFib().InOrderRecur(head);
    cout << endl;
    ergodicNorm().InOrderUnRecur(head);
    //后序遍历
    cout << "后序遍历为："<<endl;
    ergodicFib().PosOrderRecur(head);
    cout<< endl;
    ergodicNorm().PosOrderUnRecur(head);

    return 0;

}