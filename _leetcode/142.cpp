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
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        bool isSlowToGo = false;
        while (fast != NULL) {
            fast = fast->next;
            slow = isSlowToGo ? slow->next : slow;
            isSlowToGo = !isSlowToGo ;
            if (slow == fast) {
                ListNode *ptr = head;
                while (ptr != slow) {
                    slow = slow->next;
                    ptr = ptr->next;
                }
                return ptr;
            }
        }
        return nullptr;

    }
};