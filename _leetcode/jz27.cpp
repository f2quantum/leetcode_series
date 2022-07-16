//
// Created by FranklinZQuantum on 2021/11/1.
//


# include <iostream>
# include <string.h>
# include "algorithm"
# include "vector"
# include "queue"
# include "stack"
# include "unordered_set"
# include "unordered_map"
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    //请完成一个函数，输入一个二叉树，该函数输出它的镜像。
    TreeNode* mirrorTree(TreeNode* root) {
        std::queue<TreeNode*> queue1;
        if(root!= nullptr)queue1.push(root);
        while(!queue1.empty()){
            TreeNode* node = queue1.front();
            if(node->left!= nullptr){
                queue1.push(node->left);

            }
            if(node->right!= nullptr){
                queue1.push(node->right);
            }
            TreeNode* tmp = node->left;
            node->left = node ->right;
            node->right = tmp;
            queue1.pop();
        }
        return root;
    }
};
int main() {
    Solution s;
    auto inputVector = vector<int>();
    return 0;
}
