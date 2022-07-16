//
// Created by 23095 on 2021/11/3.
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
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int m =grid.size();
        int n =grid[0].size();
        int dp[m][n];
        dp[0][0]=grid[0][0];
        for(int i =1 ;i<m;i++){
            dp[i][0]=dp[i-1][0]+grid[i][0];
        }
        for(int j =1 ;j<n;j++){
            dp[0][j]=dp[0][j-1]+grid[0][j];
        }
        for(int i =1 ;i<m;i++){
            for(int j =1 ;j<n;j++){
                dp[i][j]= max(dp[i][j-1]+grid[i][j],dp[i-1][j]+grid[i][j]);
            }
        }
        return dp[m-1][n-1];
    }
};

int main() {
    Solution s;
    auto inputVector = vector<int>();
    return 0;
}
