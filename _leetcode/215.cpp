//
// Created by fzquantum on 2022/3/28.
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
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pQueue;
        int n = nums.size();
        for(int i = 0 ;i<n;i++){
            pQueue.push(nums[i]);
        }
        while(k>0){
            k--;
            pQueue.pop();
        }
        return pQueue.top();
    }
};
int main() {
    Solution s;
    auto inputVector = vector<int>();
    return 0;
}