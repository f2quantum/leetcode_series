//
// Created by FranklinZQuantum on 2021/8/19.
//


# include <iostream>
# include <string>
# include "vector"
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int left =0 ;
        int right =n;
        int mid;
        while(left<right){
            mid =left+(right - left)/2;
            if(nums[mid]>target){
                right = mid;
            } else if(nums[mid]<target){
                left = mid +1;
            }else{
                return mid;
            }
        }
        return left;
    }
};
int main(){
    Solution s;
    vector<int> nums = {1,3,5,6};
    int res=s.searchInsert(nums,2);
    cout <<res;
}