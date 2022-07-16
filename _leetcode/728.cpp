//
// Created by fzquantum on 2022/3/31.
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
    vector<int> getDigit(int d){
        unordered_set<int> digitSet;
        while(d>0){
            digitSet.insert(d%10);
            d/=10;
        }
        std::vector<int> output(digitSet.begin(), digitSet.end());

        return output;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for(int i = left ;i<=right;i++){
            vector<int> digit = getDigit(i);
            int flag = 1;
            for(auto n:digit){
                if(n==0||i%n!=0){
                    flag=0;
                    break;
                }

            }
            if(flag==1) res.push_back(i);
        }
        return  res;
    }
};
int main() {
    Solution s;
    s.getDigit(114514);
    auto inputVector = vector<int>();
    return 0;
}