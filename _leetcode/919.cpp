//
// Created by Fzquantum on 2022/7/25.
//

# include <iostream>
# include <cstring>
# include "algorithm"
# include "vector"
# include "queue"
# include "stack"
# include "unordered_set"
# include "unordered_map"
# include "math.h"
#ifdef CLIONENV
int debug = 1;
#include "../lib/dataStruct.h"
#endif
#ifndef CLIONENV
int debug = 0;
#endif
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// 使用队列进行实现
class CBTInserter {
private:
    //用队列存储可以添加子节点的节点
    queue<TreeNode*> qu;
    TreeNode* root;
public:
    CBTInserter(TreeNode* root) {
        this->root = root;
        queue<TreeNode*> q0;

        q0.push(root);
        //把最下一层全部入队
        while (!q0.empty()){
            TreeNode* node = q0.front();
            q0.pop();

            if(node->left){
                q0.push(node->left);
            }
            if(node->right){
                q0.push(node->right);
            }
            if(!(node->left &&node->right)){
                qu.push(node);
            }
        }
    }

    int insert(int val) {
        TreeNode* front = qu.front();
        int ret = front->val;
        TreeNode* newNode = new TreeNode(val);
        if(front->left== nullptr){
            front->left= newNode;
        }
        else {
            front->right= newNode;
            qu.pop();
        }
        qu.push(newNode);

        return ret;
    }

    TreeNode* get_root() {
        return  root;
    }
};


int main114514() {
    vector<int> input = {8, -8};
    CBTInserter cbtInserter = CBTInserter(new TreeNode(1));
    cout << cbtInserter.insert(2);
    return 0;
}
