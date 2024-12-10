// #include <iostream>
// #include <vector>
// #include <string>
// #include <algorithm>
// using namespace std;

// int maxRemovals(string mainString, vector<string> &substrings) {
//     int maxCount = 0;
//     for (const string &sub : substrings) {
//         size_t pos = mainString.find(sub);
//         if (pos != string::npos) {
//             string newString = mainString;
//             newString.erase(pos, sub.size());
//             maxCount = max(maxCount, 1 + maxRemovals(newString, substrings));
//         }
//     }
//     return maxCount;
// }

// int main() {
//     int n;
//     cin >> n;
//     vector<string> substrings(n);
//     for (int i = 0; i < n; i++) cin >> substrings[i];
//     string mainString;
//     cin >> mainString;
//     cout << maxRemovals(mainString, substrings) << endl;
//     return 0;
// }
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

int maxRemovals(string mainString, vector<string> &substrings, unordered_map<string, int> &memo) {
    if (memo.find(mainString) != memo.end()) return memo[mainString];
    int maxCount = 0;
    for (const string &sub : substrings) {
        size_t pos = mainString.find(sub);
        if (pos != string::npos) {
            string newString = mainString;
            newString.erase(pos, sub.size());
            maxCount = max(maxCount, 1 + maxRemovals(newString, substrings, memo));
        }
    }
    return memo[mainString] = maxCount;
}

int main() {
    int n;
    cin >> n;
    vector<string> substrings(n);
    for (int i = 0; i < n; i++) cin >> substrings[i];
    string mainString;
    cin >> mainString;
    unordered_map<string, int> memo;
    cout << maxRemovals(mainString, substrings, memo) << endl;
    return 0;
}
