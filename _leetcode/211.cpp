//
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

/**
 * 请你设计一个数据结构，支持 添加新单词 和 查找字符串是否与任何先前添加的字符串匹配 。
 */
using namespace std;

class Trie {
private:
    bool isEnd; //该结点是否是一个串的结束
    Trie *next[26]; //字母映射表

public:
    Trie() {
        isEnd = false;
        memset(next, 0, sizeof(next));
    }

    void insert(string word) {
        Trie *node = this;
        for (char c: word) {
            if (node->next[c - 'a'] == nullptr) {
                node->next[c - 'a'] = new Trie();
            }
            node = node->next[c - 'a'];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        Trie *node = this;
        int n = word.size();

        for (int i = 0; i < n; i++) {
            char c = word[i];
            if (c == '.') {
                int flag = 0;
                for (Trie *t: node->next) {
                    if (t != nullptr)
                        flag += searchSubString(t,word.substr(i+1));
                }
                if (flag > 0) return true;
                else return false;
            } else {
                node = node->next[c - 'a'];
                if (node == nullptr) return false;
            }
        }

        return node->isEnd;
    }


    bool searchSubString(Trie *root, string word) {
        Trie *node = root;
        int n = word.size();

        for (int i = 0; i < n; i++) {
            char c = word[i];
            if (c == '.') {
                int flag = 0;
                for (Trie *t: node->next) {
                    if (t != nullptr)
                        flag += searchSubString(t,word.substr(i+1));
                }
                if (flag > 0) return true;
                else return false;

            } else {
                node = node->next[c - 'a'];
                if (node == nullptr) return false;
            }
        }

        return node->isEnd;
    }


};

class WordDictionary {
private:
    Trie root;
public:
    WordDictionary() {
        root = Trie();
    }

    void addWord(string word) {
        root.insert(word);
    }

    bool search(string word) {
        return root.search(word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
int main() {
    WordDictionary w = WordDictionary();
    w.addWord("bad");
    w.addWord("dad");
    w.addWord("mad");
    w.addWord("pad");
    cout << w.search(".ad") << endl ;
    cout << w.search("b..") << endl ;
    return 0;
}
