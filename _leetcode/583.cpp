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
    // 给定两个单词 word1 和 word2 ，返回使得 word1 和  word2 相同所需的最小步数。
    // 编辑距离 删除2 等于增加 1
    int minDistance(string word1, string word2) {
        int n1 = word1.length();
        int n2 = word2.length();
        vector<vector<int>> dp = vector<vector<int>>(n1+1,vector<int>(n2+1 ,0));
        dp[0][0]=0;
        for(int i=1;i<n1+1;i++){ // 空字符串到长度为x的字符串距离都为x
            dp[i][0]=i;
        }
        for(int i=1;i<n2+1;i++){
            dp[0][i]=i;
        }
        for(int i =1;i<=n1;i++){
            for(int j = 1;j<=n2;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                } else{
                    dp[i][j] = min(dp[i-1][j]+1,min(dp[i][j-1]+1,dp[i-1][j-1]+2));
                }
            }
        }
        return dp[n1][n2];

    }
};
int main114514() {
    Solution s;
    vector<int> input = {8, -8};
    s.minDistance("sea","eat");
    return 0;
}
