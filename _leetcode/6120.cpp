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
    /*
     * 返回一个下标从 0 开始、长度为 2 的整数数组 answer 作为答案，
     * 其中 answer[0] 是形成的数对数目，answer[1] 是对 nums 尽可能执行上述操作后剩下的整数数目。
     */
    vector<int> numberOfPairs(vector<int>& nums) {
        int n  = nums.size();
        unordered_map<int,int> map;

        int ans1=0,ans2=0;
        for(auto num:nums){
            if(map.find(num)!=map.end()){
                auto iter = map.find(num);
                int cur = iter->second;
                map.erase(num);
                map.emplace(num,cur+1);
            }else{
                map.emplace(num,1);
            }
        }

        for(auto iter = map.begin();iter!=map.end();iter++){
            int key = iter->first,val = iter->second;
            int tuples = val /2;
            ans1 +=tuples;
        }

        ans2 = n - (2 * ans1);

        vector<int> res = {ans1,ans2};
        return res;




    }
};
int main114514() {
    Solution s;
    vector<int> input = {1,3,2,1,3,2,2};
    s.numberOfPairs(input);
    return 0;
}
