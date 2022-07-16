//
// Created by fzquantum on 2022/3/28.
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
    bool hasAlternatingBits(int n) {
        int last = n%2;
        while(n>0){

            n = n >> 1;
            if(last==n%2)
                return false;
            last = n%2;
        }
        return true;
    }
};
int main() {
    Solution s;
    auto inputVector = vector<int>();
    s.hasAlternatingBits(5);
    return 0;
}