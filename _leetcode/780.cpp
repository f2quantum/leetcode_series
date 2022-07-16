//
// Created by FranklinZQuantum on 2021/8/25.
//


# include <iostream>
# include <string>
#include <unordered_set>
# include "set"

using namespace std;

class Point {
public:
    int x;
    int y;

    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }

    bool operator<(const Point tp) const {
        if (this->x < tp.x && this->y < tp.y) {
            return true;
        } else {
            return false;
        }
    }

    bool operator=(const Point tp) const {
        if (this->x == tp.x && this->y == tp.y) {
            return true;
        } else {
            return false;
        }
    }
};


//搜索 逆推法
//sx, sy, tx, ty 是范围在 [1, 10^9] 的整数。
class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {

        while (tx > 0 && ty > 0) {
            if (tx == sx && ty == sy) {
                return true;
            }
            //每次逆推只能有tx、ty中较大值减去若干个较小值
            if (tx > ty) {
                tx -= max(1, (tx - sx) / ty) * ty;
            } else {
                ty -= max(1, (ty - sy) / tx) * tx;
            }
        }
        return false;
    }
};

int main() {
    int a=15, b=240;
    cout << (a&b)&b|| b;
    return 0;
}
