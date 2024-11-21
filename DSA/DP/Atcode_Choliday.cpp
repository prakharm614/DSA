#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> dp(n, vector<int>(3, 0));
    
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (i == 0) {
            dp[i][0] = a;
            dp[i][1] = b;
            dp[i][2] = c;
        } else {
            // ith day = a
            dp[i][0] = a + max(dp[i-1][1], dp[i-1][2]);
            // ith day = b
            dp[i][1] = b + max(dp[i-1][0], dp[i-1][2]);
            // ith day = c
            dp[i][2] = c + max(dp[i-1][0], dp[i-1][1]);
        }
    }

    cout << max({dp[n-1][0], dp[n-1][1], dp[n-1][2]}) << "\n";
    return 0;
}
