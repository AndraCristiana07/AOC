#include <bits/stdc++.h>
using namespace std;


bool isNiceString(string str) {
    // 1
    int vowelCount = 0;
    for (char c : str) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            vowelCount++;
            if (vowelCount >= 3) {
                break;
            }
        }
    }

    //2
    bool hasDoubleLetter = false;
    for (int i = 0; i < str.length() - 1; i++) {
        if (str[i] == str[i + 1]) {
            hasDoubleLetter = true;
            break;
        }
    }

    //3
    bool notallowed = false;
    for (int i = 0; i < str.length() - 1; i++) {
        if ((str[i] == 'a' && str[i + 1] == 'b') ||
            (str[i] == 'c' && str[i + 1] == 'd') ||
            (str[i] == 'p' && str[i + 1] == 'q') ||
            (str[i] == 'x' && str[i + 1] == 'y')) {
            notallowed = true;
            break;
        }
    }

    return vowelCount >= 3 && hasDoubleLetter && !notallowed;
}

int main() {
    auto in = ifstream("input.in");
    string word;
    int niceCount = 0;

    while (getline(in, word)) {
        if (isNiceString(word)) {
            niceCount++;
        }
    }

    cout << "nice strings: " << niceCount << endl;
    return 0;
}