#include <iostream>

using namespace std;

bool isSquare(int grid[10][10], int n) {
    // Iterate through each cell
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            // Check if the current cell is 1
            if (grid[i][j] == 1) {
                // Try to form a square starting from this cell
                for (int k = 2; k <= n - i; ++k) {
                    // Check if forming a square of size k x k is possible
                    bool isSquare = true;
                    for (int l = 0; l < k; ++l) {
                        // Check if the consecutive row has k consecutive 1s
                        if (grid[i + l][j] != 1 || grid[i + l][j + k - 1] != 1) {
                            isSquare = false;
                            break;
                        }
                    }
                    if (isSquare) {
                        // Check if there is a square of size k x k
                        bool validSquare = true;
                        for (int l = 0; l < k; ++l) {
                            for (int m = 0; m < k; ++m) {
                                if (grid[i + l][j + m] != 1) {
                                    validSquare = false;
                                    break;
                                }
                            }
                            if (!validSquare) break;
                        }
                        if (validSquare) return true;
                    }
                }
            }
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int grid[10][10];

        // Input grid
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> grid[i][j];
            }
        }

        if (isSquare(grid, n)) {
            cout << "SQUARE" << endl;
        } else {
            cout << "TRIANGLE" << endl;
        }
    }

    return 0;
}
