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
    /**
        滑动窗口
     * @param answerKey
     * @param k
     * @return
     */
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size();
        int left = 0;
        int ansT = 0;
        int ansF = 0;
        int sum = 0;
        int right = 0;
        for(left= 0,right=0,sum = 0;right<n;right++){
            sum+=(answerKey[right]!='T');
            while(sum>k){
                sum-=(answerKey[left]!='T');
                left++;
            }
            ansT = max(ansT,right-left+1);
        }
        for(left= 0,right=0,sum = 0;right<n;right++){
            sum+=(answerKey[right]!='F');
            while(sum>k){
                sum-=(answerKey[left]!='F');
                left++;
            }
            ansF = max(ansF,right-left+1);
        }
        return  max(ansT,ansF);
    }
};
int main() {
    Solution s;
    auto inputVector = vector<int>();
    return 0;
}