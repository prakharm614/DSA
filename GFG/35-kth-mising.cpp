// C++ Program to find Kth missing positive number
// using Binary Search

#include <iostream>
#include <vector>
using namespace std;

// Function to find the k-th missing positive number
int kthMissing(vector<int> &arr, int k) {
    int lo = 0, hi = arr.size() - 1;
    int res = arr.size() + k;

    // Binary Search for index where arr[i] > (i + k)
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (arr[mid] > mid + k) {
            res = mid + k;
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
    }

    return res;
}

int main() {
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;
    cout << kthMissing(arr, k);
    return 0;
}