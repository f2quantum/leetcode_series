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
    // 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角
    int uniquePaths(int m, int n) {
        vector<vector<int>>  dp = vector<vector<int>>(m+1,vector<int>(n+1,0));
        dp[0][0] = 1;
        for(int i=0;i<=m;i++){
            dp[i][0]=1;
        }
        for(int i=0;i<=n;i++){
            dp[0][i]=1;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];

    }
};
int main114514() {
    Solution s;
    vector<int> input = {8, -8};

    return 0;
}
