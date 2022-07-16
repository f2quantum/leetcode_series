//
// Created by FranklinZQuantum on 2021/8/14.
//


# include <iostream>
# include <string>
#include "unordered_set"

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0){
            return 0;
        }
        unordered_set<char> lookup;
        int maxLength = 0;
        int left =0 ;
        for(int right =0 ; right < s.length(); right++){
            while (lookup.find(s[right]) != lookup.end()){//lookup中存在 s[right]
                lookup.erase(s[left]);
                left ++;
            }
            maxLength = max(maxLength,right-left+1);
            lookup.insert(s[right]);

        }
        return maxLength;
    }
};
int main() {
    system("pause");
    return 0;
}
