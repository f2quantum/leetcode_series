//
// Created by FranklinZQuantum on 2021/8/28.
//


# include <iostream>
# include <string>
# include "vector"
# include "math.h"
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int nums =strs.size();
        vector<char> prefix;
        int minLength =200;
        for (int i=0;i<nums;i++){
            minLength= min(minLength,(int)strs[i].length());
        }
        bool flag = true;
        for (int i=0;i<minLength&&flag;i++){
            for(int j=0;j<nums&&flag;j++){
                if(j==0){
                    prefix.push_back(strs[j][i]);

                } else{
                    if(prefix[i]!=strs[j][i]){
                        prefix.pop_back();
                        flag= false;
                    } else{
                        continue;
                    }
                }
            }
        }
        string result="";
        for (vector<char>::iterator iter = prefix.begin(); iter != prefix.end(); ++iter)
        {
            result  += *iter;
        }
        return result;

    }
};
int main() {
    Solution s;
    vector<string> input ={"dog","racecar","car"};
    cout << s.longestCommonPrefix(input);
    return 0;
}
