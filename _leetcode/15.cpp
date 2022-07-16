//
// Created by Fzquantum on 2022/7/15.
//

# include <iostream>
# include <string.h>
# include "algorithm"
# include "vector"
# include "queue"
# include "stack"
# include "unordered_set"
# include "unordered_map"
/**
 * 双指针法
 * -10^5 <= nums[i] <= 10^5
 */
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_set<long long > memory;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> resultSet;
        // 答案中不可以包含重复的三元组。
        for(int i=1;i<n-1;i++){
            int left = 0, right = n-1;
            int sum = nums[left]+nums[right]+nums[i];
            while (sum!=0){
               if(sum<0){
                   left++;
               } else{
                   right--;
               }
                if(left>=i||right<=i) break;
                sum = nums[left]+nums[right]+nums[i];
            }
            if(sum == 0){
                vector<int> tuple = {nums[left],nums[i],nums[right]};
                resultSet.push_back(tuple);
            }
        }
        return resultSet;
    }
};
int main() {
    Solution s;
    vector<int> input = {8, -8};

    return 0;
}
