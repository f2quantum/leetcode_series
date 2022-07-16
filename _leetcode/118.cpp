//
// Created by FranklinZQuantum on 2021/8/24.
//


# include <iostream>
# include <string>
# include "vector"

using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        result.push_back({1});
        for(int i=1;i<numRows;i++){
            vector<int> rows;
            rows.push_back(1);
            for(int j=1;j<i;j++){
                int left = result.at(i-1).at(j-1);
                int right = result.at(i-1).at(j);
                rows.push_back(left+right);
            }
            rows.push_back(1);
            result.push_back(rows);
        }
        return result;

    }
};
int main() {
    Solution s;
    s.generate(10);
    return 0;
}
