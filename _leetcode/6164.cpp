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
    int maximumSum(vector<int>& nums) {

        int n  = nums.size();
        unordered_map<int,int> map;
        int maxCups = -1;

        for(auto num:nums){
            int bitSum = calcNum(num);
            if(map.find(bitSum)!=map.end()){
                auto iter = map.find(bitSum);
                int curSameBitNum = iter->second;
                maxCups = max(maxCups, curSameBitNum + num);

                curSameBitNum = max(curSameBitNum, num);
                map.erase(bitSum);
                map.emplace(bitSum, curSameBitNum);
            }else{
                map.emplace(bitSum,num);
            }
        }
        return maxCups;
    }
    int calcNum(int x){
        int re = 0;
        while(x>0){
            re+=x%10;
            x/=10;
        }
        return re;
    }
};
int main114514() {
    Solution s;
    vector<int> input = {18,43,36,13,7};
    cout << s.maximumSum(input);
    return 0;
}
