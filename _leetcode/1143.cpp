//
// Created by Fzquantum on 2022/7/17.
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

    // dp[i][j] = 1. dp[i-1][j-1]+1              if text1[i] == text2[j]
    //            2. max(dp[i-1][j],dp[i][j-1])  if text1[i] != text2[j]
    // 动态规划？dp[i][j] 表示 text1[0:i]与text[0:2]的公共子序列长度
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.length();
        int n2 = text2.length();
        vector<vector<int>> dp = vector<vector<int>>(n1+1,vector<int>(n2+1 ,0));
        dp[0][0]=0;
        for(int i=1;i<n1+1;i++){
            dp[i][0]=0;
        }
        for(int i=1;i<n2+1;i++){
            dp[0][i]=0;
        }
        for(int i =1;i<=n1;i++){
            for(int j = 1;j<=n2;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                } else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n1][n2];
    }
};
int main114514() {
    Solution s;
    vector<int> input = {8, -8};
    cout << s.longestCommonSubsequence("abc","abc");
    return 0;
}
