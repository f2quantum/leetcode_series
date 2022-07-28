//
// Created by Fzquantum on 2022/7/14.
//
#define clionenv
#ifndef LEETCODE_SERIES_DATASTRUCT_H
#define LEETCODE_SERIES_DATASTRUCT_H
class Trie ;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#endif //LEETCODE_SERIES_DATASTRUCT_H
