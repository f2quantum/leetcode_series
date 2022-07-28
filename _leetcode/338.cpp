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
    //计算其二进制表示中 1 的个数
    vector<int> countBits(int n) {
        vector<int> dp = vector<int>(n+1,0);
        dp[0]=0;
        if(n==0) return{0};
        dp[1]=1;
        if(n==1) return{0,1};
        for(int i=2;i<=n;i++){
            if(i%2!=0){ // 奇数 1的个数加一
                dp[i]=dp[i-1]+1;
            } else{ // 偶数，1的个数等于其除以2的数1的个数（最后一位为0）
                dp[i]=dp[i>>1];
            }
        }
        return dp;
    }
};
int main114514() {
    Solution s;
    vector<int> input = {8, -8};

    return 0;
}
