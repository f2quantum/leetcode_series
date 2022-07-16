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

#ifdef CLIONENV
int debug = 1;
#endif
#ifndef CLIONENV
int debug = 0;
#endif
// 你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
using namespace std;
class Solution {
public:
    // 亦或
    int singleNumber(vector<int>& nums) {
        int i =0;
        for(int n :nums){
            i = i xor n;
        }
        return i;
    }
};
int main114514() {
    Solution s;
    vector<int> input = {8, -8};

    return 0;
}
