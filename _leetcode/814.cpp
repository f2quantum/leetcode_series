//
// Created by Fzquantum on 2022/7/21.
//

# include <iostream>
# include <cstring>
#include <sstream>
# include "algorithm"
# include "vector"
# include "queue"
# include "stack"
# include "unordered_set"
# include "unordered_map"

#ifdef CLIONENV
int debug = 1;
#include "../lib/dataStruct.h"
#endif
#ifndef CLIONENV
int debug = 0;
#endif
using namespace std;

class Solution {
public:
    // 返回移除了所有不包含 1 的子树的原二叉树。
    TreeNode* pruneTree(TreeNode* root) {
        if(root == nullptr) return nullptr;
        if(!contains1(root)){
            root = nullptr;
            return root;
        }
        if(!contains1(root->left)){
            root->left = nullptr;
        } else{
            pruneTree(root->left);
        }
        if(!contains1(root->right)){
            root->right = nullptr;
        }else{
            pruneTree(root->right);
        }
        return root;
    }

    bool contains1(TreeNode* root){
        if(root== nullptr) return false;
        return root->val==1 || contains1(root->left) || contains1(root->right);
    }
};


void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

TreeNode* stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

string treeNodeToString(TreeNode* root) {
    if (root == nullptr) {
        return "[]";
    }

    string output = "";
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node == nullptr) {
            output += "null, ";
            continue;
        }

        output += to_string(node->val) + ", ";
        q.push(node->left);
        q.push(node->right);
    }
    return "[" + output.substr(0, output.length() - 2) + "]";
}

int main114514() {
    string line = "[0,null,0,0,0]";

        TreeNode* root = stringToTreeNode(line);

        TreeNode* ret = Solution().pruneTree(root);

        string out = treeNodeToString(ret);
        cout << out << endl;

    return 0;
}