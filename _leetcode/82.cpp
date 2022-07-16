//
// Created by Fzquantum on 2022/7/15.
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

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
/**
 * 开头加一个哑巴节点 防止删除头的情况出现
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        int prevVal =  -111;
        ListNode* superHead = new ListNode(-114514,head);

        ListNode* node = superHead;
        while (node->next&&node->next->next){
            if(node->next->val == node->next->next->val){
                int sameVal =node->next->val;
                while (node->next &&node->next->val ==sameVal){
                    node->next = node->next->next;
                }
            } else{
                node = node->next;
            }
        }
        return superHead->next;
    }
};
int main() {
    Solution s;
    vector<int> input = {8, -8};

    return 0;
}
