class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
           // code here
         int m = matrix.size();
    int n = matrix[0].size();

    vector<int> res;

    int top = 0, bottom = m - 1, left = 0, right = n - 1;

    while (top <= bottom && left <= right) {

        // Print top row from left to right
        for (int i = left; i <= right; ++i) {
            res.push_back(matrix[top][i]);
        }
        top++;

        // Print right column from top to bottom
        for (int i = top; i <= bottom; ++i) {
            res.push_back(matrix[i][right]);
        }
        right--;

        // Print bottom row from right to left (if exists)
        if (top <= bottom) {
            for (int i = right; i >= left; --i) {
                res.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        // Print left column from bottom to top (if exists)
        if (left <= right) {
            for (int i = bottom; i >= top; --i) {
                res.push_back(matrix[i][left]);
            }
            left++;
        }
    }

    return res;
    
    }
};