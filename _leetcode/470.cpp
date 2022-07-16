//
// Created by fzquantum on 2022/3/30.
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
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7
extern int rand7();
class Solution {
public:
    int rand2(){
        int a = rand7();
        return  a==7?rand2():a%2;
    }
    int rand10() {
        int ans = rand2();
        for(int i=0;i<4;i++){
            ans <<=1;
            ans ^= rand2();
        }
        return ans>0&&ans<=10?ans:rand10();
    }
};
int main() {
    Solution s;
    auto inputVector = vector<int>();
    return 0;
}