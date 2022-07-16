//
// Created by FranklinZQuantum on 2021/9/6.
//


# include <iostream>
# include <string>
# include "vector"

using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int n =s.size();
        if(n<2){
            return s;
        }
        int maxLen = 1;
        int begin = 0;

        vector<vector<int>> dp(n, vector<int>(n));
        // 初始化：所有长度为 1 的子串都是回文串
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        for(int L =2 ;L <=n;L++){
            for (int i = 0; i < n; i++) {
                int j= L+i-1;
                if(j>=n){
                    break;
                }
                if (s[i] != s[j]) {
                    dp[i][j] = false;
                }else {
                    if (j - i < 3) {//长度为1或2
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }
                // 只要 dp[i][L] == true 成立，就表示子串 s[i..L] 是回文，此时记录回文长度和起始位置
                if (dp[i][j] && j - i + 1 > maxLen) {
                    maxLen = j - i + 1;
                    begin = i;
                }

            }


        }


    return s.substr(begin, maxLen);

};
int main() {
    Solution s;
    return 0;
}
