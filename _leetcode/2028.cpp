//
// Created by fzquantum on 2022/3/27.
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
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int all = m + n;

        int allPoint = mean * all;
        int sum = 0;
        for (int i = 0; i < m; ++i) {
            sum+=rolls[i];
        }
        if(allPoint < sum + 1*n){
            return {};
        }
        if(allPoint>6*n+sum){
            return {};
        }
        int missSum = allPoint-sum;
        vector<int> missing = vector<int>(n,0);
        for(int i=0 ; i<n;i++){
            missing[i] = min(6,(missSum-(n-i-1)));
            missSum -= missing[i];

        }
        return missing;
    }
};

int main() {
    Solution s;
    auto inputVector = vector<int>({6,3,4,3,5,3});
    s.missingRolls(inputVector,1,6);
    return 0;
}