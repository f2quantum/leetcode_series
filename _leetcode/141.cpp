#include <cstddef>
#include <unordered_set>
#include "vector"
#include "algorithm"

using namespace std;
//
// Created by FranklinZQuantum on 2021/8/6.
//
typedef struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
} ListNode;

class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode *> set;
        while (head != NULL) {
            if (set.find(head) != set.end()) {
                return true;
            } else {
                set.insert(head);
            }
            head = head->next;

        }
        return false;

    }
};