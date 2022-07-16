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

#ifdef clionenv
#define main114514 main
#endif

/**
 * 你必须设计一个时间复杂度为 O(log n) 的算法解决此问题。
 */
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {

        int n = nums.size();
        int start = nums[0];
        int idx = -1;
        int l=0,r=n-1;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (nums[mid] >= nums[0]) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }


        if(target>nums[0]){
            int left = 0,right = r;
            while(left< right){
                int mid = (left+ right+1)/2;
                if(nums[mid]==target) return mid;
                else if (nums[mid]>target){
                    right = mid -1;
                } else{
                    left = mid;
                }
            }
        } else if (target<nums[0]){
            int left = r,right = n-1;
            while(left< right){
                int mid = (left+ right+1)/2;
                if(nums[mid]==target) return mid;
                else if (nums[mid]>target){
                    right = mid-1;
                } else{
                    left = mid;
                }
            }
        } else{
            return 0;
        }

        return -1;
    }
};
int main() {
    Solution s;
    vector<int> input = {1,3};
    cout << s.search(input,3);

    return 0;
}
