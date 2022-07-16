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
// 双指针，字符串替换后匹配
using namespace std;
class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();
        auto s = start, t = target;
        s.erase(remove(s.begin(), s.end(), '_'), s.end());
        t.erase(remove(t.begin(), t.end(), '_'), t.end());
        if (s != t) return false;
        for(int i=0,j=0;i<n;i++,j++){
            while (start[i]=='_') i++;
            while (target[j]=='_') j++;
            if(start[i]=='L'){ //L 只能左移
                if(i<j) return false;
            }
            if(start[i]=='R'){
                if(i>j) return false;
            }
        }
        return true;
    }
};
int main() {
    Solution s;
    vector<int> input = {8, -8};
    cout << s.canChange("_L__R__R_","L______RR");
    return 0;
}
