//
// Created by Fzquantum on 2022/7/17.
//

# include <iostream>
# include <string.h>
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
    // 请你返回子数组内所有元素的乘积严格小于 k 的连续子数组的数目。
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k==1) return 0;
        if(k==0) return 0;
        int res = 0;
        int n = nums.size();
        int l = 0 , r = 0;
        int sum = 1;
        while (r<n){
            sum*=nums[r];
            while(sum>=k&&l<n){
                sum/=nums[l];
                l++;
            }
            // sum <k
            if(debug) cout << "l: " << l << " r: " << r << endl;
            res += (r-l+1);
            r++;
        }
        return res;
    }
};
int main114514() {
    Solution s;
//    vector<int> input = {10,5,2,6};
//    cout<< s.numSubarrayProductLessThanK(input,100);
    vector<int> input = {1,1,1};
    cout<< s.numSubarrayProductLessThanK(input,1);
    return 0;
}
