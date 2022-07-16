//
// Created by Fzquantum on 2022/1/8.
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

    vector<int> res ;
    vector<bool>* visit;

    int exceptResSize;
    vector<int> grayCode(int n) {
        exceptResSize = 1<<n;
        vector<bool> visit (exceptResSize,0);
        this->visit = &visit;
        dfs(0,n);
        return res;
    }
    bool dfs(int cur,int n){
        if(res.size() == exceptResSize)
            return true;
        res.push_back(cur);
        (*visit)[cur]=true;
        for(int i=0;i<n;i++){
            int next = cur ^(1<<i);
            if(!(*visit)[next]){
                if(dfs(next,n)){
                    return true;
                }
            }
        }
        return false;
    }

};
int main() {
    Solution s;
    auto inputVector = vector<int>({0,1,3,2});
    s.grayCode(2);
    return 0;
}
