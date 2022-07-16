//
// Created by FranklinZQuantum on 2021/8/24.
//


# include <iostream>
# include <string>
# include "vector"

using namespace std;
class Solution {
public:
    //f(x) = max( f(x-1)+nums[x],nums[x])
    int maxSubArray(vector<int>& nums) {
        int n =nums.size();
        int MAX= nums[0];
        int last =nums[0];
        for(int i=1;i< n;i++){
            last = max(last+nums[i],nums[i]);
            MAX=max(MAX,max(last,nums[i]));
        }
        return MAX;
    }
};
int main() {
    Solution s;
    vector<int> in= {-2,1,-3,4,-1,2,1,-5,4};
    int result=s.maxSubArray(in);
    return 0;
}
