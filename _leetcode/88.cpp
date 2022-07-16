//
// Created by fzquantum on 2022/3/30.
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
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0) return ;
        int min1 = nums1[0];
        for(int i=0;i<n;i++){
            nums1[m+i]=nums2[i];
        }
        sort(nums1.begin(),nums1.end());
    }
};
int main() {
    Solution s;
    auto inputVector = vector<int>();
    return 0;
}