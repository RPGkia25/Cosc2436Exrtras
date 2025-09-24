#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int merge = nums1.size() +nums2.size();
        vector<double> arr(merge);

        int i = 0;
        int j = 0;
        int k = 0;

        // Merge both arrays
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                arr[k++] = nums1[i++];
            } else {
                arr[k++] = nums2[j++];
            }
        }

        // Copy remaining elements
        while (i < nums1.size()) {
            arr[k++] = nums1[i++];
        }
        while (j < nums2.size()) {
            arr[k++] = nums2[j++];
        }

        //find median
        if(arr.size()%2 == 0){
            double median = arr[arr.size()/2-1] + arr[arr.size()/2];
            return median/2;
        }else{
            return arr[ceil(arr.size()/2)];
        }
        }
};

int main()
{
    Solution sol;

    vector<int> nums1 = {1, 2, 7};
    vector<int> nums2 = {3, 4, 5, 6};

    double median = sol.findMedianSortedArrays(nums1, nums2);

    cout << "Median is: " << median << endl;

    return 0;
}