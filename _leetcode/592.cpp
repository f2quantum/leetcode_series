//
// Created by Fzquantum on 2022/7/27.
//

# include <iostream>
# include <cstring>
# include "algorithm"
# include "vector"
# include "queue"
# include "stack"
# include "unordered_set"
# include "unordered_map"
#include "numeric"
#ifdef CLIONENV
int debug = 1;

# include  "../lib/dataStruct.h"

#endif
#ifndef CLIONENV
int debug = 0;
#endif
using namespace std;
// 模拟
//输入: expression = "-1/2+1/2+1/3"
// 每个分数的分子与分母的范围是  [1,10]
class Solution {
public:
    string fractionAddition(string expression) {
        vector<int> ups;
        vector<int> downs;
        int i = 0;
        int n = expression.size();
        while (i<n){
            char c = expression[i];
            int sign = 1;
            if(c=='-'||c=='+'){
                if(c=='-'){
                    sign = -1;
                }
                i++;
            }
            // 分子
            char upc = expression[i];
            int upi = upc - '0';
            if(upc=='1'){
                if(expression[i+1]=='0'){
                    upi= 10;
                    i++;
                }
            }
            i++;
            ups.push_back(sign*upi);
            // "/"
            i++;
            // 分母
            char downc = expression[i];
            int downi = downc - '0';
            if(downc=='1'){
                if(expression[i+1]=='0'){
                    downi= 10;
                    i++;
                }
            }
            downs.push_back(downi);
            i++;
        }

        int upr = 0;
        int downr = 1;
        // 计算
        for(int i =0;i<ups.size();i++){

            upr =(upr*downs[i]+ups[i]*downr);
            downr = downr * downs[i];

        }

        int gcd = std::gcd(upr,downr);
        upr/=gcd;
        downr/=gcd;
        string ret ;

        ret.append(to_string(upr));
        ret.append("/");
        ret.append(to_string(downr));

        return ret;

    }


};
int main114514() {
    Solution s;
    vector<int> input = {8, -8};
    cout <<s.fractionAddition("1/3-1/2");
    return 0;
}
