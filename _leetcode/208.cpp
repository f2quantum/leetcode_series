﻿//
// Created by Fzquantum on 2022/7/14.
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

class Trie {
private:
    bool isEnd; //该结点是否是一个串的结束
    Trie* next[26]; //字母映射表

public:
    Trie() {
        isEnd = false;
        memset(next,0, sizeof(next));
    }

    void insert(string word) {
        Trie* node  = this;
        for(char c:word){
            if(node->next[c-'a']==nullptr){
                node->next[c-'a'] = new Trie();
            }
            node = node->next[c-'a'];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        Trie* node = this;
        for(char c:word){
            node = node->next[c-'a'];
            if(node == nullptr) return false;
        }
        return node->isEnd;
    }

    bool startsWith(string prefix) {
        Trie* node = this;
        for(char c:prefix){
            node = node->next[c-'a'];
            if(node == nullptr) return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
int main() {
    vector<int> input = {8, -8};

    return 0;
}
