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

using namespace std;
/**
 * 你必须实现时间复杂度为 O(log n) 的算法来解决此问题。
 * 二分法
 */
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0,right = nums.size()-1;
        while (left<right){
            int mid = (left + right )/2;
            if(nums[mid]>nums[mid+1]){
                right = mid;
            } else {
                left =mid+1;
            }
        }
        return left;

    }
};
int main() {
    Solution s;
    vector<int> input = {8, -8};

    return 0;
}
