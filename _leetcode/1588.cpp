//
// Created by FranklinZQuantum on 2021/8/29.
//


# include <iostream>
# include <string>
# include "vector"

using namespace std;
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int sum=0;
        int result =0;
        vector<int> prefixSum;
        prefixSum.push_back(0);
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            prefixSum.push_back(sum);
        }
        for(int l=1 ;l<=arr.size();l+=2){
            for(int i=0;i+l-1<arr.size();i++){
                result+=(prefixSum[i+l]-prefixSum[i]);
            }
        }
        return result;
    }
};
int sumOddLengthSubarrays(vector<int>& arr) {
    int sum=0;
    int result =0;
    vector<int> prefixSum;
    prefixSum.push_back(0);
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
        prefixSum.push_back(sum);
    }
    for(int l=1 ;l<=arr.size();l+=2){
        for(int i=0;i+l-1<arr.size();i++){
            result+=(prefixSum[i+l]-prefixSum[i]);
        }
    }
    return result;
}
int main() {
    vector<int> arr = {1,4,2,5,3};
    cout << sumOddLengthSubarrays(arr);
    return 0;
}
