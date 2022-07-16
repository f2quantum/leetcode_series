//
// Created by FranklinZQuantum on 2021/8/5.
//
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            if (nums.at(i) == nums.at(i + 1)) {
                return true;
            }
        }
        return false;
    }
};

