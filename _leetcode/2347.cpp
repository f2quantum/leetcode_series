//
// Created by Fzquantum on 2022/7/26.
//

# include <iostream>
# include <cstring>
# include "vector"
# include "queue"
# include "stack"
# include "unordered_set"
# include "unordered_map"

#ifdef CLIONENV
int debug = 1;

# include  "../lib/dataStruct.h"

#endif
#ifndef CLIONENV
int debug = 0;
#endif
using namespace std;
class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        int n =5;
        //"Flush"：同花，五张相同花色的扑克牌。
        for(int i=0;i<n-1;i++){
            if(suits[i]!=suits[i+1]){
                break;
            }
            if(i==3){
                return "Flush";
            }
        }
        //"Three of a Kind"：三条，有 3 张大小相同的扑克牌。
        unordered_map<int,int> cnt;
        int flag2=0,flag3 = 0;
        for(int i=0;i<n;i++){
            if(cnt.find(ranks[i])==cnt.end()){
                cnt.emplace(ranks[i],1);
            }else{
                int val = cnt.find(ranks[i])->second;
                cnt.erase(ranks[i]);
                cnt.emplace(ranks[i],val+1);
            }
            if(cnt.find(ranks[i])->second>=3){
                flag3= 1;
            }
            if(cnt.find(ranks[i])->second>=2){
                flag2= 1;
            }


        }
        if(flag3)
            return "Three of a Kind";

        if(flag2)
            return "Pair";
        //"High Card"：高牌，五张大小互不相同的扑克牌。
        return "High Card";
    }
};
int main114514() {
    Solution s;
    vector<int> input = {13,2,3,1,9};
    vector<char> input2 = {'a','a','a','a','a'};
    cout << s.bestHand(input,input2);
    return 0;
}
