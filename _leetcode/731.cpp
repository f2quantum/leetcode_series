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
class MyCalendarTwo {
private:
    vector<pair<int,int>> overlap;
    vector<pair<int,int>> booked;
public:
    MyCalendarTwo() {

    }
     // 即 [start, end), 实数 x 的范围为，  start <= x < end。
    bool book(int start, int end) {
        for(auto [l,r]:overlap){
            if(l<end&&r>start){ // overlap 和区间重叠
                return false;
            }
        }
         for(auto [l,r]:booked){
             if(l<end&&r>start){ // overlap 和区间重叠
                 overlap.emplace_back(max(l,start),min(r,end));
             }
         }
         booked.emplace_back(start,end);
         return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
int main114514() {
    vector<int> input = {8, -8};

    return 0;
}
