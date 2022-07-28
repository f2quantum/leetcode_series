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
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>>  dp = vector<vector<int>>(m,vector<int>(n,0));
        if(obstacleGrid[0][0]==1||obstacleGrid[m-1][n-1]) return 0;
        dp[0][0] = 1;
        bool isRow0hasObs = false,isCol0hasobs = false;
        for(int i=0;i<m;i++){
            int j=0;
            if(obstacleGrid[i][j]==1||isRow0hasObs){
                dp[i][j]=0;
                isRow0hasObs = true;
            } else{
                dp[i][j]=1;

            }
        }
        for(int j=0;j<n;j++){
            int i=0;
            if(obstacleGrid[i][j]==1||isCol0hasobs){
                dp[i][j]=0;
                isCol0hasobs = true;
            } else{
                dp[i][j]=1;

            }

        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j]==1){
                    dp[i][j]=0;
                } else{
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];

                }
            }
        }
        return dp[m-1][n-1];

    }
};
int main114514() {
    Solution s;
    vector<vector<int>> input = {{0,0},{1,0}};
    cout << s.uniquePathsWithObstacles(input);
    return 0;
}
