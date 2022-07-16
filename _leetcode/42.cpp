//
// Created by FranklinZQuantum on 2021/10/26.
//


# include <iostream>
# include <string>
# include "vector"

using namespace std;
class Solution {
public:

    int trap(vector<int>& height) {
        // 蓄水容量 = min(左边的最高的height，右边最高的height)
        int res=0;

        int leftMaxHeight=0;
        int rightMaxHeight=0;

        int left =0 ;
        int right =height.size()-1;

        while(left<=right){
            if(leftMaxHeight<=rightMaxHeight){
                leftMaxHeight = max(leftMaxHeight,height[left]);
                res+= leftMaxHeight-height[left];
                left++;
            }else{
                rightMaxHeight = max(rightMaxHeight,height[right]);
                res+= rightMaxHeight-height[right];
                right--;
            }

        }
        return res;
    }
};
int main() {
    Solution s;
    vector<int> in = {4,2,0,3,2,5};
    cout << s.trap(in);
    return 0;
}
