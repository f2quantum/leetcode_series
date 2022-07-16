//
// Created by FranklinZQuantum on 2021/8/14.
//

//给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
//
// 请你将两个数相加，并以相同形式返回一个表示和的链表。
//
// 你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
//
 struct ListNode {
         int val;
         ListNode *next;
         ListNode() : val(0), next(nullptr) {}
         ListNode(int x) : val(x), next(nullptr) {}
         ListNode(int x, ListNode *next) : val(x), next(next) {}
     } ;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr;
        ListNode* cursor = head;

        int carry =0 ;
        while(l1 != nullptr || l2 != nullptr){
            int curL1 = l1 != nullptr ?l1->val:0;
            int curL2 = l2 != nullptr ?l2->val:0;
            int sum = curL1 + curL2 +carry;
            carry = sum /10;
            if(head != nullptr ){
                cursor ->next=  new ListNode(sum%10);
                cursor = cursor ->next;
            } else{
                head =cursor = new ListNode(sum%10);
            }
            if(l1!= nullptr){
                l1=l1->next;
            }
            if(l2!= nullptr){
                l2=l2->next;
            }

        }
        if (carry != 0 ){
            cursor ->next=  new ListNode(carry);
            cursor = cursor ->next;
        }

        return head;
    }
};