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
    int numTrees(int n) {
        vector<int> dp  = vector<int>(n+4,0);
        dp[0]=1;
        if(n==0) return 1;
        if(n==1) return 1;
        if(n==2) return 2;
        dp[1]=1;
        dp[2]=2;
        for(int i = 3;i<=n;i++){
            int sum =0;
            for(int j =0;j<i;j++){
                sum+=dp[j]*dp[i-j-1];
            }
            dp[i]=sum;
        }
        return dp[n];
    }
};
int main114514() {
    Solution s;
    vector<int> input = {8, -8};
    cout << s.numTrees(3);
    return 0;
}
