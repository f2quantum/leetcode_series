//
// Created by FranklinZQuantum on 2021/10/27.
//


# include <iostream>
# include <string>
# include "vector"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        ListNode* node=head;
        ListNode* prev = nullptr;
        ListNode* next =head;
        while(next!= nullptr){
            next = node->next;
            node -> next =prev;
            prev = node;
        }
        return node;
    }
};

int main() {
    Solution s;
    ListNode* l5=new ListNode(5, nullptr);
    ListNode* l4=new ListNode(4, l5);

    ListNode* l3=new ListNode(3, l4);

    ListNode* l2=new ListNode(2, l3);

    ListNode* l1=new ListNode(1, l2);
    s.reverseList(l1);
    return 0;
}
