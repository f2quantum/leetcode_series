//
// Created by Fzquantum on 2022/7/15.
//

# include <iostream>
# include <string.h>
# include "algorithm"
# include "vector"
# include "queue"
# include "stack"
# include "unordered_set"
# include "unordered_map"
#ifdef CLIONENV
int debug =1;
#endif
#ifndef CLIONENV
int debug = 0;
#endif
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        //get line
        int l = -1,r =m-1;
        while (l<r){
            int c = l+(r-l+1)/2;
            if(matrix[c][0]>target){
                r = c  ;
            } else if(matrix[c][n-1]<target){
                l = c - 1 ;
            } else{  // inside
                int left = 0,right = n-1;
                while (left<=right){
                    int c2 = left + (right -left )/2;
                    if(matrix[c][c2]>target){
                        left = c2 +1;
                    } else if(matrix[c][c2]==target){
                        return true;
                    } else{
                        right = c2 -1 ;
                    }
                    if(debug) cout << "2: " <<left << " " << right <<endl;

                }
                return 0;
            }
            if(debug) cout << "1: " << l << " " << r <<endl;
        }
        return false;
    }
};
int main114514() {
    Solution s;
    vector<vector<int>> input = {{1}};
    cout << s.searchMatrix(input,1);
    return 0;
}
