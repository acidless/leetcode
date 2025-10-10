/*
Problem: Median of Two Sorted Arrays
Link: https://leetcode.com/problems/median-of-two-sorted-arrays
Approach: Binary Search, O(log(m + n))
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>& A = nums1;
        vector<int>& B = nums2;

        int totalSize = A.size() + B.size();
        int half = (totalSize + 1) / 2;

        if (B.size() < A.size()) {
            swap(A, B);
        }

        int l = 0;
        int r = A.size();
        while (l <= r) {
            int i = (l + r) / 2;
            int j = half - i;

            int Aleft = i > 0 ? A[i - 1] : numeric_limits<int>::min();
            int Aright = i < A.size() ? A[i] : numeric_limits<int>::max();
            int Bleft = j > 0 ? B[j - 1] : numeric_limits<int>::min();
            int Bright = j < B.size() ? B[j] : numeric_limits<int>::max();

            if (Aleft <= Bright && Bleft <= Aright) {
                if (totalSize & 1) {
                    return max(Aleft, Bleft);
                }

                return (max(Aleft, Bleft) + min(Aright, Bright)) / 2.0f;
            } else if (Aleft > Bright) {
                r = i - 1;
            } else {
                l = i + 1;
            }
        }

        return -1;
    }
};
