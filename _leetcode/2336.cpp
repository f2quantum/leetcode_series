//
// Created by Fzquantum on 2022/7/13.
//

# include <iostream>
# include <string.h>
# include "algorithm"
# include "vector"
# include "queue"
# include "stack"
# include "set"
# include "unordered_set"
# include "unordered_map"

using namespace std;
class SmallestInfiniteSet {
public:
    int minE;
    set<int> removeSet;
    // 初始化 SmallestInfiniteSet 对象以包含 所有 正整数
    SmallestInfiniteSet() {
        minE = 1;
    }
    //  移除 并返回该无限集中的最小整数。
    int popSmallest(){
        removeSet.insert(minE);
        int res  = minE++;
        while(removeSet.count(minE)!=0){
            minE++;
        }
        return res;
    }
    // 如果正整数 num 不 存在于无限集中，则将一个 num 添加 到该无限集中。
    void addBack(int num) {
        if(num< minE){
            removeSet.erase(num);
            minE = num;
        } else{
            removeSet.erase(num);
        }


    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
int main() {
    SmallestInfiniteSet s;
    vector<int> input = {8, -8};

    return 0;
}
