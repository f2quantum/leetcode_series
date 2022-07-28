//
// Created by Fzquantum on 2022/7/26.
//

# include <iostream>
# include <cstring>
# include "algorithm"
# include "vector"
# include "queue"
# include "stack"
# include "unordered_set"
# include "unordered_map"

#ifdef CLIONENV
int debug = 1;

# include  "../lib/dataStruct.h"

#endif
#ifndef CLIONENV
int debug = 0;
#endif
using namespace std;
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0,r= 0;
        long long  subArrayCnt = 0;
        long long ret = 0;

        for(int i=0;i<n;i++){
            if(nums[i]==0){
                subArrayCnt++;
            } else{
                while(subArrayCnt>0){
                    ret+=subArrayCnt--;
                }
            }
        }
        while(subArrayCnt>0){
            ret+=subArrayCnt--;
        }
        return ret;
    }
};
int main114514() {
    Solution s;
    vector<int> input = {8, -8};

    return 0;
}
