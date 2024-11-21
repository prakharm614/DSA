#include <iostream>
using namespace std;

void HollowSquare(int n) {
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || i == n - 1 || j == 0 || j == n - 1) {
                cout << "* ";
            } else {
                cout << "  ";  
            }
        }
        cout << endl; 
    }
}

int main() {
    int size;
    cout << "Enter the size of the square: ";
    cin >> size;

    HollowSquare(size);

    return 0;
}
