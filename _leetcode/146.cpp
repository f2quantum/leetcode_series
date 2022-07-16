//
// Created by FranklinZQuantum on 2021/10/26.
//


# include <iostream>
# include <string>
#include <unordered_map>
# include "vector"
//运用你所掌握的数据结构，设计和实现一个 LRU (最近最少使用) 缓存机制 。
//实现 LRUCache 类：
//
//LRUCache(int capacity) 以正整数作为容量capacity 初始化 LRU 缓存
//int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
//void put(int key, int value)如果关键字已经存在，则变更其数据值；如果关键字不存在，则插入该组「关键字-值」。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。
//
//
//进阶：你是否可以在O(1) 时间复杂度内完成这两种操作？
using namespace std;
struct DLinkdListNode{
    int key,value;
    DLinkdListNode* prev;
    DLinkdListNode* next;
    DLinkdListNode(): key(0) , value(0),prev(nullptr),next(nullptr){}
    DLinkdListNode(int _key,int _value): key(_key) , value(_value),prev(nullptr),next(nullptr){}
};
class LRUCache {
//    双向链表按照被使用的顺序存储了这些键值对，靠近头部的键值对是最近使用的，而靠近尾部的键值对是最久未使用的。
//
//    哈希表即为普通的哈希映射（HashMap），通过缓存数据的键映射到其在双向链表中的位置。

// 插入一个元素，就将其移动到双向链表头部 用HashMap简历key到Node的索引
private:
    unordered_map<int,DLinkdListNode*> cache;
    DLinkdListNode* head;
    DLinkdListNode* tail;
    int size;
    int capacity;

public:

    LRUCache(int capacity) {
        this->capacity=capacity;
        //伪头部和尾部
        head = new DLinkdListNode();
        tail = new DLinkdListNode();
        head->next=tail;
        tail->prev=head;
        size =0;
    }

    int get(int key) {
        if(cache.count(key)==0){
            return  -1;

        } else{
            DLinkdListNode* target = cache[key];
            //remove old one
            target->prev->next=target->next;
            target->next->prev=target->prev;
            //move to head;
            DLinkdListNode* oldFirst = head->next;
            oldFirst ->prev =target;
            head->next =target;
            target->next=oldFirst;
            target->prev = head;

            return target->value;
        }
    }

    void put(int key, int value) {
        if(cache.count(key)==0){
            DLinkdListNode* newNode = new  DLinkdListNode(key,value);
            cache[key] = newNode;

            DLinkdListNode* oldFirst = head->next;
            head -> next = newNode;
            newNode -> prev = head;
            newNode -> next = oldFirst;
            oldFirst -> prev =newNode;
            size++;

            if(size>capacity){
                // remove last one
                DLinkdListNode* last = tail->prev;

                last ->prev->next =tail;
                tail ->prev =last ->prev;

                cache.erase(last->key);
                size--;
            }

        }else{
            //moveToHead
            DLinkdListNode* exist = cache[key];
            exist->value =value;
            // remove old one
            exist->prev->next=exist->next;
            exist->next->prev=exist->prev;
            //insert new one
            DLinkdListNode* oldFirst = head->next;
            oldFirst ->prev =exist;
            exist->next=oldFirst;
            head->next =exist;
            exist->prev = head;
        }


    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
int main() {
    LRUCache lRUCache =  LRUCache(2);
     lRUCache.put(1, 1); // 缓存是 {1=1}
     lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
    cout << lRUCache.get(1) <<endl;    // 返回 1
     lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
     cout << lRUCache.get(2) <<endl;    // 返回 -1 (未找到)
     lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
     cout << lRUCache.get(1) <<endl;    // 返回 -1 (未找到)
     cout << lRUCache.get(3) <<endl;    // 返回 3
     cout << lRUCache.get(4) <<endl;    // 返回 4

    return 0;
}
