// C++ program to search in the sorted matrix using
// Binary Search two times

#include <iostream>
#include <vector>
using namespace std;

// Function to binary search for x in arr[]
bool search(vector<int> &arr, int x) {
    int lo = 0, hi = arr.size() - 1;

    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        if (x == arr[mid])
            return true;
        if (x < arr[mid])
            hi = mid - 1;
        else
            lo = mid + 1;
    }
    return false;
}

bool searchMatrix(vector<vector<int>> &mat, int x) {
    int n = mat.size(), m = mat[0].size();
    int lo = 0, hi = n - 1;
    int row = -1;

    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        // If the first element of mid row is equal to x,
        // return true
        if (x == mat[mid][0])
            return true;
      
        // If x is greater than first element of mid row,
        // store the mid row and search in lower half
        if (x > mat[mid][0]) {
            row = mid;
            lo = mid + 1;
        }
      
        // If x is smaller than first element of mid row,
        // search in upper half
        else
            hi = mid - 1;
    }
   
    // If x is smaller than all elements of mat[][]
    if (row == -1)
        return false;

    return search(mat[row], x);
}

int main() {
    vector<vector<int>> mat = {{1, 5, 9}, {14, 20, 21}, {30, 34, 43}};
    int x = 14;

    if (searchMatrix(mat, x))
        cout << "true";
    else
        cout << "false";

    return 0;
}