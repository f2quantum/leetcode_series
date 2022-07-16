//
// Created by FranklinZQuantum on 2021/8/19.
//

// 进阶：
//
//
// 请你设计时间复杂度为 O(n) 的算法解决本问题
//
// Related Topics 数组 双指针 排序 👍 274 👎 0
#include <iostream>
#include "vector"
using namespace std;
//_leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int negPosition=-1;
        int n = nums.size();
        vector<int> ans;
        for (int i=0;i<nums.size()-1;i++){
            if( nums[i]<0 && nums[i+1]>=0){
                negPosition =i;
                break;
            }
        }
        if(negPosition == -1){
            if (nums[0]<0){//全为负数
                negPosition =n-1;
            } else{//全为非负数
                negPosition= -1;
            }
        }
        int l = negPosition;
        int r =negPosition +1;
        while(l>=0||r<n){
            int left=0 ,right=0 ;
            bool flagL= false,flagR= false;
            if(l>=0){
                left = nums[l]*nums[l];
                flagL= true;
            }
            if(r<n){
                right =nums[r]*nums[r];
                flagR = true;
            }
            if(flagL&&flagR){
                if(left>right){
                    ans.push_back(right);
                    r++;
                } else{
                    ans.push_back(left);
                    l--;
                }
            } else if(flagL){
                ans.push_back(left);
                l--;
            } else if(flagR){
                ans.push_back(right);
                r++;
            }



        }
        return ans;
    }
};
//_leetcode submit region end(Prohibit modification and deletion)
int main(){
    Solution s;
    vector<int> num ={1,2,3,4,6};
    vector<int> result =s.sortedSquares(num);
    std::cout << 1;

}