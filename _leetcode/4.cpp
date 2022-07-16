//
// Created by FranklinZQuantum on 2021/10/26.
//

/**
 * 给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。

请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

你可以假设 nums1 和 nums2 不会同时为空

 */
# include <iostream>
# include <string>
#include <cmath>
# include "vector"

using namespace std;
class Solution {
public:
    int getKthElement(const vector<int>& nums1, const vector<int>& nums2, int k){
        int m = nums1.size();
        int n = nums2.size();
        int index1left = 0, index2left = 0;
        while (1){
            //处理边界条件
            if(index1left==m){
                return nums2[index2left+k-1];
            }
            if(index2left==n){
                return nums1[index1left+k-1];
            }
            if(k==1){
                return min(nums1[index1left],nums2[index2left]);
            }
            // 取 k/2+1  控制边界条件
            int newIndex1Left=min(index1left+k/2-1,m-1);
            int newIndex2Left = min(index2left+k/2-1,n-1);

            int mid1=nums1[newIndex1Left];
            int mid2=nums2[newIndex2Left];

            // 修正新的k值为m+n的 1/2(因为排除了newIndex1Left-index1left+1个元素)
            if(mid1<=mid2){
                k = k - (newIndex1Left-index1left) -1;
                index1left= newIndex1Left+1;
            }else{
                k = k - (newIndex2Left-index2left) -1;
                index2left=newIndex2Left+1;
            }


        }
        return 0;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l1= nums1.size();
        int l2= nums2.size();
        int totalLength = l1+l2;

        if(totalLength%2==0){//偶数
            return (getKthElement(nums1,nums2,totalLength/2)+getKthElement(nums1,nums2,totalLength/2+1))/2.0;

        } else{//奇数
            return getKthElement(nums1,nums2,(totalLength+1)/2);
        }

    }
};
int main() {
    Solution s;
    return 0;
}
