// Problem: Search a 2D Matrix
// Link: https://leetcode.com/problems/search-a-2d-matrix
// Approach: O(log(m * n))

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return binarySearch(matrix, 0, matrix.size() * matrix[0].size(), target);
    }

    bool binarySearch(vector<vector<int>>& matrix, int l, int r, int target) {
        if(l >= r) {
            return false;
        }

        int mid = (l + r) / 2;
        int row = mid / matrix[0].size();
        int col = mid % matrix[0].size();

        if(matrix[row][col] == target) {
            return true;
        }

        if(matrix[row][col] > target) {
            return binarySearch(matrix, l, mid, target);
        } else {
            return binarySearch(matrix, mid + 1, r, target);
        }
    }
};
