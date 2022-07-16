//
// Created by FranklinZQuantum on 2021/8/24.
//


# include <iostream>
# include <string>
# include "vector"

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };
//左中右
class Solution {
public:
    vector<int> result;
    void inorderTraversal1(TreeNode* root) {
        if(root == nullptr ){
            return;
        }
        if(root->left != nullptr){
            inorderTraversal1(root->left);
        }

         result.push_back(root->val);
        if(root->right!= nullptr){
            inorderTraversal1(root->right);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        inorderTraversal1(root);
        return result;
    }
};
int main() {
    Solution s;
    return 0;
}
