//
// Created by 23095 on 2021/11/1.
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    bool helper(TreeNode* left,TreeNode* right){
        if(left== nullptr&&right== nullptr){
            return true;
        }
        else if(left== nullptr||right== nullptr){
            return false;
        }else {
            return left->val==right->val&& helper(left->left,right->right)&& helper(left->right,right->left);
        }
    }
    bool isSymmetric(TreeNode* root) {
        if(root== nullptr) return true;
        return helper(root->left,root->right);
    }
};

int main() {
    Solution s;
    auto inputVector = vector<int>();
    return 0;
}
