//
// Created by Fzquantum on 2022/7/26.
//

# include <iostream>
# include <cstring>
# include "algorithm"
# include "vector"
# include "queue"
# include "stack"
# include "unordered_set"
# include "unordered_map"
# include "map"
#ifdef CLIONENV
int debug = 1;

# include  "../lib/dataStruct.h"

#endif
#ifndef CLIONENV
int debug = 0;
#endif
using namespace std;
class NumberContainers {
    //1 <= index, number <= 109
private:
    map<int,int,less<int>> map;
public:
    NumberContainers() {

    }

    void change(int index, int number) {
        map[index] = number;
    }

    int find(int number) {
        for(auto iter:map){
            if(iter.second==number){
                return iter.first;
            }
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
int main114514() {
    vector<int> input = {8, -8};

    return 0;
}
