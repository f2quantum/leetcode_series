//
// Created by Fzquantum on 2022/7/19.
//

# include <iostream>
# include <cstring>
# include "algorithm"
# include "vector"
# include "queue"
# include "stack"
# include "unordered_set"
# include "unordered_map"

#ifdef CLIONENV
int debug = 1;
#endif
#ifndef CLIONENV
int debug = 0;
#endif
using namespace std;
class Solution {
public:
    // 原地优化 节约空间
    vector<int> getRow(int rowIndex) {
        vector<int> row = vector<int>(rowIndex+1,0);
        int prev = 0;
        for(int i=1;i<=rowIndex+1;i++){
            row[0]=1;
            prev = row[0];
            for(int j = 1 ;j<i;j++){
                if(j==i-1){
                    row[j]=1;
                } else{
                    int left = prev;
                    int right = row[j];
                    prev = row[j];
                    row[j]= left + right;
                }
            }

        }
        return row;


    }
};
int main114514() {
    Solution s;
    vector<int> input = {8, -8};
    s.getRow(3);
    return 0;
}
