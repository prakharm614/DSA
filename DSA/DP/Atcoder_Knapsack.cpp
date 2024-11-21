// #include <iostream>
// #include <algorithm>
// #define ll long long
// using namespace std;

// int helper(ll wt[], ll val[], ll idx, ll w, ll n) {
//     if (idx == n || w == 0) {
//         return 0;
//     } else {
//         // Do not include the current item
//         ll withoutCurrent = helper(wt, val, idx + 1, w, n);
        
//         // Include the current item if possible
//         if (wt[idx] <= w) {
//             ll withCurrent = helper(wt, val, idx + 1, w - wt[idx], n) + val[idx];
//             return max(withCurrent, withoutCurrent);
//         }
        
//         return withoutCurrent;
//     }
// }

// int main() {
//     ll n, w;
//     cin >> n >> w;
//     ll wt[n];
//     ll val[n];
//     for (int i = 0; i < n; i++) {
//         cin >> wt[i] >> val[i];
//     }

//     cout << helper(wt, val, 0, w, n) << endl;

//     return 0;
// }
#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;

vector<vector<ll>> dp;

ll helper(ll wt[], ll val[], ll idx, ll w, ll n) {
    if (idx == n || w == 0) {
        return 0;
    }

    if (dp[idx][w] != -1) {
        return dp[idx][w]; 
    }

    ll withoutCurrent = helper(wt, val, idx + 1, w, n);
    ll withCurrent = 0;
    if (wt[idx] <= w) {
        withCurrent = helper(wt, val, idx + 1, w - wt[idx], n) + val[idx];
    }

    return dp[idx][w] = max(withCurrent, withoutCurrent);
}


// bottom up = 

// int main() {
//     ll n, w;
//     cin >> n >> w;
//     ll wt[n];
//     ll val[n];

//     for (int i = 0; i < n; i++) {
//         cin >> wt[i] >> val[i];
//     }

//     // DP table
//     ll dp[n + 1][w + 1];

//     // Initialize the DP table
//     for (int i = 0; i <= n; i++) {
//         for (int j = 0; j <= w; j++) {
//             if (i == 0 || j == 0) {
//                 dp[i][j] = 0;
//             } else if (wt[i - 1] <= j) {
//                 dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
//             } else {
//                 dp[i][j] = dp[i - 1][j];
//             }
//         }
//     }

//     cout << dp[n][w] << endl;

//     return 0;
// }

int main() {
    ll n, w;
    cin >> n >> w;
    ll wt[n];
    ll val[n];

    dp = vector<vector<ll>>(n + 1, vector<ll>(w + 1, -1));// also can be set to max limit that is n+1 -> 105, w+1 -> 100005

    for (int i = 0; i < n; i++) {
        cin >> wt[i] >> val[i];
    }

    cout << helper(wt, val, 0, w, n) << endl;

    return 0;
}
