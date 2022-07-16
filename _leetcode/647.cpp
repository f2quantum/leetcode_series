//
// Created by FranklinZQuantum on 2021/10/26.
//


# include <iostream>
# include <string>
# include "vector"

using namespace std;
class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        //初始化长度为1的字符串
        for(int i=0;i<n;i++){
            dp[i][i]= true;
        }
        //遍历长度
        for(int L=2;L<=n;L++){
            for(int l=0; l < n-L +1; l++){
                int r = l + L - 1;
                if(r-l<=2){ //长度为 1 or 2
                    s[l]==s[r]?dp[l][r]= true:dp[l][r]= false;
                }else{
                    if(s[l]==s[r]){
                        dp[l][r]=dp[l+1][r-1];
                    }else{
                        dp[l][r]= false;
                    }
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dp[i][j]== true) cnt++;
            }
        }
        return cnt;


    }
};
int main() {
    Solution s;
    cout << s.countSubstrings("abc");
    return 0;
}
