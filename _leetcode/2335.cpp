//
// Created by Fzquantum on 2022/7/13.
//

# include <iostream>
# include <string.h>
# include "algorithm"
# include "vector"
# include "queue"
# include "stack"
# include "unordered_set"
# include "unordered_map"
# include "math.h"
using namespace std;
class Solution {
public:
    int fillCups(vector<int>& amount) {
        int cnt = 0;
        sort(amount.begin(),amount.end());
        while (amount[2]>0){
            if(amount[1]>0&&amount[2]>0){
                amount[1]--;
                amount[2]--;
                cnt ++;
            }
            else if (amount[2]>0){
                amount[2]--;
                cnt++;
            }
            sort(amount.begin(),amount.end());
        }


        return cnt;
    }
};
int main() {
    Solution s;
    vector<int> input = {5,4,4};
    cout << s.fillCups(input);
    return 0;
}
