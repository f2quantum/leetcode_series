//
// Created by Fzquantum on 2022/7/19.
//

# include <iostream>
# include <cstring>
# include "algorithm"
# include "vector"
# include "queue"
# include "stack"
# include "unordered_set"
# include "unordered_map"

#ifdef CLIONENV
int debug = 1;
#endif
#ifndef CLIONENV
int debug = 0;
#endif
using namespace std;
class Solution {
public:
    // 字符串的一个子序列是原始字符串删除一些
    bool isSubsequence(string s, string t) {

        int sl = 0;
        int tl =0;
        int len1 = s.size();
        int len2 = t.size();
        while(sl<len1&&tl<len2){
            if(s[sl]==t[tl]){
                sl++;
            }
            tl++;
        }
        if(sl==len1){
            return true;
        }
        return false;
    }
};
int main114514() {
    Solution s;
    vector<int> input = {8, -8};
    s.isSubsequence("abc","ahbgdc");
    return 0;
}
