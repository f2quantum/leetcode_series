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
/**
 * 约瑟夫环
 * 1. 队列模拟
 */
using namespace std;
class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> qu;
        for(int i=1;i<=n;i++){
            qu.push(i);
        }
        int cnt = 0;
        int idx;
        while (qu.size()>1){
            idx = qu.front();
            qu.pop();
            cnt++;
            if(cnt%k!=0) qu.push(idx);
        }
        return qu.front();

    }
};
int main114514() {
    Solution s;
    vector<int> input = {8, -8};

    return 0;
}
