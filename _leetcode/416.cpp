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
    // 0-1 背包问题??
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(auto num:nums){
            sum+=num;
        }
        if(sum%2!=0){
            return false;
        }
        int target = sum/2;
        vector<vector<int>> dp = vector<vector<int>>(n+2,vector<int>(target+2,0));
        dp[0][0]=1;
//        for(int i=1;i<=target;i++){
//            dp[0][i]=0;
//        }
//        for(int i=1;i<=n;i++){
//            dp[i][0]=0;
//        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<= target;j++){
                if(nums[i-1]>j){
                    dp[i][j]=dp[i-1][j];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i-1][j-nums[i-1]]);//max(选取j,不选举j);
                }
            }
        }

        return dp[n][target];
    }
};
int main114514() {
    Solution s;
    vector<int> input = {8, -8};

    return 0;
}
