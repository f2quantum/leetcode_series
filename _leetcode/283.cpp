//
// Created by FranklinZQuantum on 2021/8/19.
//


# include <iostream>
# include <string>
# include "vector"
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n =nums.size();
        int countNonZero = 0;
        for(int i=0;i<n;i++){
           if(nums[i]!=0){
               swap(nums[countNonZero++],nums[i]);

           }

        }
    }
};
int main() {
    Solution s;
    vector<int> input ={0,1,0,0,0,0,3,12};
    s.moveZeroes(input);
    return 0;
}
