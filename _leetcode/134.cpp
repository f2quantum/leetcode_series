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
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas .size();
        if(n == 1) return gas[0]>=cost[0]?0:-1;
        for(int i =0 ;i<n;i++){

                int sumOfGas = 0, sumOfCost = 0;
                int cnt = 0;
                while(cnt < n){
                    int next = (cnt + i) %n;
                    sumOfGas +=gas[next];
                    sumOfCost+=cost[next];
                    if(sumOfCost>sumOfGas){
                        break;
                    }
                    cnt++;
                }
                if(cnt==n) return i;
                i = i+ cnt;
            }

        return -1;
    }
};
int main() {
    Solution s;
    auto inputVector = vector<int>();
    return 0;
}