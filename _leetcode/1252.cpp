//
// Created by Fzquantum on 2022/7/12.
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
    /*
     * 模拟
     */
    int oddCells0(int m, int n, vector<vector<int>>& indices) {
        vector<vector<int>> matrix =  vector<vector<int>>(m,vector<int>(n,0));
        for(auto index:indices){
            int r = index[0],c = index[1];
            for(int i=0;i<n;i++){ //ri 行上的所有单元格，加 1 。
                matrix[r][i]++;
            }
            for(int j= 0;j< m;j++){ // ci 列上的所有单元格，加 1
                matrix[j][c]++;
            }
        }
        int cnt = 0;
        for(int i = 0 ;i< m;i++){
            for(int j = 0 ; j<n;j++){
                cnt +=(matrix[i][j]%2==1);
            }
        }
        return cnt;
    }

    /*
     * 你可以设计一个时间复杂度为 O(n + m + indices.length) 且仅用 O(n + m) 额外空间的算法来解决此问题吗？
     * 用一个行数组 \textit{rows}rows 和列数组 \textit{cols}cols 分别记录每一行和每一列被增加的次数
     */
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<int> rows = vector<int>(m,0),cols = vector<int>(n,0);
        for(auto index:indices){
            int r = index[0],c = index[1];
            rows[r]++;
            cols[c]++;
        }
        int cnt = 0;
        for(int i = 0 ;i< m;i++){
            for(int j = 0 ; j<n;j++){
                cnt +=((rows[i]+cols[j])%2==1);
            }
        }

        return cnt;
    }
};
int main() {
    return 0;
}
