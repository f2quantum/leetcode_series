//
// Created by fzquantum on 2022/3/29.
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
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans0, ans1;
        unordered_set<int> set1;
        unordered_set<int> set2;
        for(int i =0;i<nums1.size();i++){
            set1.insert(nums1[i]);
        }
        for(int i =0;i<nums2.size();i++){
            set2.insert(nums2[i]);
        }
        for(auto num:set1){
            if(set2.find(num)==set2.end()){
                ans0.push_back(num);
            }
        }
        for(auto num:set2){
            if(set1.find(num)==set1.end()){
                ans1.push_back(num);
            }
        }

        return {ans0,ans1};
    }
};
int main() {
    Solution s;
    auto inputVector = vector<int>({1,2,3,3});
    auto inputVecto1r = vector<int>({1,1,2,2});
    s.findDifference(inputVector,inputVecto1r);

    return 0;
}