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
    // 一旦你支付此费用，即可选择向上爬一个或者两个台阶。
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp = vector<int>(n+1,0);
        dp[0]=0;
        dp[1]=0;
        for(int i=2;i<=n;i++){
            dp[i]=min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2]);
        }
        return dp[n];
    }
};
int main114514() {
    Solution s;
    vector<int> input = {8, -8};

    return 0;
}
