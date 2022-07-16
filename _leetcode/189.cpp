//
// Created by FranklinZQuantum on 2021/8/19.
//


# include <iostream>
# include <string>
# include "vector"
using namespace std;

class Solution {
public:
    void reverse(vector<int>& nums,int start,int end ){
        while(start<end){
            swap(nums[start],nums[end]);
            start++;
            end++;
        }
    }
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();

        reverse(nums,0,nums.size()-1);
        reverse(nums,0,k-1);
        reverse(nums,k,nums.size()-1);

    }
};