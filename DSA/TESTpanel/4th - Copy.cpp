#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    string res;
    cin >> str;

    // Convert capital letters to lowercase and append '.' before consonants
    for (char &c : str) {
        if (c >= 'A' && c <= 'Z') {
            c = c + 32; // Convert uppercase to lowercase by adding 32
        }
        if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' && c != 'y') {
            res += '.';
            res += c;
        }
    }

    cout << res << endl;

    return 0;
}
