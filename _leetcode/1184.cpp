//
// Created by Fzquantum on 2022/7/24.
//

# include <iostream>
# include <cstring>
# include "algorithm"
# include "vector"
# include "queue"
# include "stack"
# include "unordered_set"
# include "unordered_map"
using namespace std;

#ifdef CLIONENV
int debug = 1;
#endif
#ifndef CLIONENV
int debug = 0;
#endif
class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        if(start==destination) return 0;
        int n = distance.size();
        int clockwise = 0;
        int counterClockwise = 0;
        if(start>destination) {
            swap(start,destination);

        }
        int s = start, d = destination;
        while (s!=d){
            clockwise+=distance[s];
            s++;
        }
        while (s<n+start){
            counterClockwise+=distance[(s)%n];
            s++;
        }




        return min(clockwise,counterClockwise);
    }
};
int main114514() {
    Solution s;
    vector<int> input = {7,10,1,12,11,14,5,0};
    cout << s.distanceBetweenBusStops(input,7,2);

    return 0;
}
