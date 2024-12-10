#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
void rotateSubMatrixLayer(vector<vector<char>>& matrix, int row, int col, int size, int layer) {
    int n = size;
    int top = row + layer - 1;
    int left = col + layer - 1;
    int bottom = row + n - layer;
    int right = col + n - layer;
    
    vector<char> layerElements;

    // Top row
    for (int j = left; j < right; ++j)
        layerElements.push_back(matrix[top][j]);

    // Right column
    for (int i = top + 1; i < bottom; ++i)
        layerElements.push_back(matrix[i][right - 1]);

    // Bottom row
    for (int j = right - 2; j >= left; --j)
        layerElements.push_back(matrix[bottom - 1][j]);

    // Left column
    for (int i = bottom - 2; i > top; --i)
        layerElements.push_back(matrix[i][left]);
//rotate
    int len = layerElements.size();
    if (layer % 2 == 1) { // Odd layer - counterclockwise rotation and decrement letters
        rotate(layerElements.begin(), layerElements.begin() + (layer % len), layerElements.end());
        for (char& ch : layerElements) {
            ch = (ch == 'A') ? 'Z' : ch - 1;
        }
    } else { // Even layer - clockwise rotation and increment letters
        rotate(layerElements.rbegin(), layerElements.rbegin() + (layer % len), layerElements.rend());
        for (char& ch : layerElements) {
            ch = (ch == 'Z') ? 'A' : ch + 1;
        }
    }

    // Place the modified characters back into the matrix
    int idx = 0;

    // Top row
    for (int j = left; j < right; ++j)
        matrix[top][j] = layerElements[idx++];

    // Right column
    for (int i = top + 1; i < bottom; ++i)
        matrix[i][right - 1] = layerElements[idx++];

    // Bottom row
    for (int j = right - 2; j >= left; --j)
        matrix[bottom - 1][j] = layerElements[idx++];

    // Left column
    for (int i = bottom - 2; i > top; --i)
        matrix[i][left] = layerElements[idx++];
}

// Main function to process the matrix and queries
int main() {
    int n;
    cin >> n;

    vector<vector<char>> matrix(n, vector<char>(n));

    // Read the matrix
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    int k;
    cin >> k;

    // Process each query
    for (int i = 0; i < k; ++i) {
        int row, col, size;
        cin >> row >> col >> size;

        // For each query, rotate the sub-matrix
        for (int layer = 1; layer <= size / 2; ++layer) {
            rotateSubMatrixLayer(matrix, row, col, size, layer);
        }
    }

    // Output the final matrix as a string
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j];
        }
    }

    return 0;
}
