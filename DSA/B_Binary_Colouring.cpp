#include <iostream>
#include <vector>

using namespace std;

int getLength(int x) {
  int length = 0;
  while (x > 0) {
    x >>= 1;
    length++;
  }
  return length;
}

vector<int> getColoring(int x) {
  int length = getLength(x);
  vector<int> coloring(length, 0);
  for (int i = 0; i < length; i++) {
    if (x & (1 << i)) {
      coloring[i] = 1;
    } else if (i > 0 && coloring[i - 1] == 1) {
      coloring[i] = -1;
    }
  }
  return coloring;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int x;
    cin >> x;
    int length = getLength(x);
    vector<int> coloring = getColoring(x);
    cout << length << endl;
    for (int j = 0; j < length; j++) {
      cout << coloring[j] << " ";
    }
    cout << endl;
  }
  return 0;
}
