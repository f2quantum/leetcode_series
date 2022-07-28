//
// Created by Fzquantum on 2022/7/17.
//

# include <iostream>
# include <string.h>
#include <map>
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
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n  = nums.size();
        vector<int> res ;
        for(auto query:queries){
            int k = query[0],trim_ = query[1];
            vector<string> copy0 =  vector<string>(nums);
            int len = copy0[0].length();
            int reserve = len -trim_;
            for(int i=0;i<n;i++){
                copy0[i] = copy0[i].substr(reserve, trim_);
            }
            vector<int> idx(n);
            for(int i=0;i<n;i++){
                idx[i]=i;
            }
            sort(idx.begin(),idx.end(),[&copy0](const int& i1,const int& i2){
                if(copy0[i1] != copy0[i2]){
                    return copy0[i1] < copy0[i2];
                }else{
                    return i1<i2;
                }

            });
            res.push_back(idx[k-1]);
        }
        return res;
    }
};
int main114514() {
    Solution s;
    vector<int> input = {8, -8};
    vector<string> nums = {"64333639502","65953866768","17845691654","87148775908","58954177897","70439926174","48059986638","47548857440","18418180516","06364956881","01866627626","36824890579","14672385151","71207752868"};
    vector<vector<int>> queries = {{9,4},{6,1},{3,8},{12,9},{11,4},{4,9},{2,7},{10,3},{13,1},{13,1},{6,1},{5,10}};
    s.smallestTrimmedNumbers(nums,queries);
    return 0;
}
