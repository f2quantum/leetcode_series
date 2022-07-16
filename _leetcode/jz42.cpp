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
    int maxSubArray(vector<int>& nums) {
        int n =nums.size();
        if(n==1) return nums[0];
        int dp[n];
        dp[0]=nums[0];
        int max = dp[0];
        for(int i=1;i<n;i++){
            dp[i]=std::max(dp[i-1]+nums[i],nums[i]);
            max =std::max(dp[i],max);
        }

        return max;
    }
};

int main() {
    Solution s;
    auto inputVector = vector<int>({-2,1,-3,4,-1,2,1,-5,4});
    cout << s.maxSubArray(inputVector);
    return 0;
}
