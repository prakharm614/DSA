#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        char grid[10][10];
        bool triangle = false, square = false;

        // Input grid
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> grid[i][j];
            }
        }

        // Check for square or triangle
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - 1; ++j) {
                if (grid[i][j] == '1') {
                    if (grid[i + 1][j] == '1' && grid[i][j + 1] == '1' && grid[i + 1][j + 1] == '1') {
                        square = true;
                        break;
                    }
                    if (grid[i + 1][j] == '1' && grid[i + 2][j] == '1' && grid[i + 1][j + 1] == '1') {
                        triangle = true;
                        break;
                    }
                }
            }
            if (square || triangle) break;
        }

        if (square) {
            cout << "SQUARE" << endl;
        } else {
            cout << "TRIANGLE" << endl;
        }
    }

    return 0;
}
