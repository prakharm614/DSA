#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        // Sort the array of gas stations
        sort(arr, arr + n);

        // Calculate the maximum distance between refueling points
        int max_dist = arr[0]; // Distance from 0 to the first gas station
        for (int i = 1; i < n; i++) {
            max_dist = max(max_dist, arr[i] - arr[i - 1]);
        }
        max_dist = max(max_dist, 2*(x - arr[n - 1])); // Distance from the last gas station to x

        // The required tank capacity must be able to cover this maximum distance in one go
        cout << max_dist << endl;
    }
    return 0;
}
