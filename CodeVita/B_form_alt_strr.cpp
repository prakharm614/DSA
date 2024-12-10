#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    string binary;
    cin >> binary;
    int n = binary.length();
    vector<int> worth(n);
    for (int i = 0; i < n; i++) {
        cin >> worth[i];
    }

    // dp array to store the minimum worth of removed characters
    vector<int> dp(n, INT_MAX);
    dp[0] = 0; // First character is always kept, so no worth removed.

    // Iterate through the string
    for (int i = 1; i < n; i++) {
        dp[i] = dp[i - 1] + worth[i]; // Case: Remove the current character
        for (int j = i - 1; j >= 0; j--) {
            if (binary[i] != binary[j]) { // Check for alternating condition
                dp[i] = min(dp[i], dp[j] + (i - j - 1) * worth[i]); 
                break;
            }
        }
    }

    // Calculate the total worth of removed characters
    int totalWorth = accumulate(worth.begin(), worth.end(), 0);
    int maxAlternateWorth = totalWorth - dp[n - 1];

    cout << maxAlternateWorth << endl;
    return 0;
}
