//
// Created by Fzquantum on 2022/7/20.
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
private:
    int m,n;
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        m = grid.size(),n = grid[0].size();
        for(int i=0;i<k;i++){
            shift(grid);
        }
        return grid;
    }
    vector<vector<int>> shift(vector<vector<int>>& grid) {
        int prev,last=grid[m-1][n-1];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                prev = grid[i][j];
                grid[i][j]=last;
                last = prev;
            }
        }
        return grid;
        }
    };
int main114514() {
    Solution s;
    vector<int> input = {8, -8};

    return 0;
}
