//
// Created by FranklinZQuantum on 2021/8/5.
//
#include <unordered_set>
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int> &nums) {
        unordered_set<int> set;
        for (int x:nums) {
            if (set.find(x) != set.end()) {
                return true;
            }
            set.insert(x);

        }
        return false;
    }
};

