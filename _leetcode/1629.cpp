//
// Created by Fzquantum on 2022/1/9.
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
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int maxTime = releaseTimes[0];
        int maxIndex = 0;
        int n = releaseTimes.size();
        for(int i=1;i<n;i++){
            int lastTime = releaseTimes[i]- releaseTimes[i-1];
            if(lastTime>maxTime||(lastTime==maxTime&&keysPressed[i]>keysPressed[maxIndex])){
                maxTime = lastTime;
                maxIndex =i;
            }
        }
        return keysPressed[maxIndex];
    }
};
int main() {
    Solution s;
    auto inputVector = vector<int>({12,23,36,46,62});
    cout << s.slowestKey(inputVector,"spuda");
    return 0;
}
