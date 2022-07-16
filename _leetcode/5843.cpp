//
// Created by FranklinZQuantum on 2021/8/15.
//


# include <iostream>
# include <vector>
#include <regex>

using namespace std;
class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        smatch result;
        int n = patterns.size();
        int count = 0;
        for (int i = 0 ;i< n;i++){
            regex r(patterns.at(i));
            if (regex_search(word,result,r)==1){
                count++;
            }

        }
        return  count;

    }
};