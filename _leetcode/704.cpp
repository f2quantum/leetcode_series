//
// Created by FranklinZQuantum on 2021/9/6.
//


# include <iostream>
# include <string>
# include "vector"

using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right =nums.size();
        int mid ;
        while(left<right){
            mid =(left+right)/2;
            if(nums[mid]>target){
                right = mid;
            } else if(nums[mid]<target){
                left =mid+1;
            }else{
                return mid;
            }
        }
        return -1;
    }
};
int main() {
    Solution s;
    return 0;
}
