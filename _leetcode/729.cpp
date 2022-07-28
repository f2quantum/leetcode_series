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
class MyCalendar {
private:
    vector<pair<int,int>> booked;
public:
    MyCalendar() {

    }

    bool book(int start, int end) {
        for(auto [l,r]: booked){
            if(l<end && r>start){
                return false;
            }
        }
        booked.emplace_back(start,end);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
int main114514() {
    vector<int> input = {8, -8};

    return 0;
}
