#include <bits/stdc++.h>

using namespace std;

bool isValidPassword(string &password) {
    // increasing straight
    bool hasStraight = false;
    for (int i = 0; i < password.length() - 2; ++i) {
        if (password[i] + 1 == password[i + 1] && password[i] + 2 == password[i + 2]) {
            hasStraight = true;
            break;
        }
    }

    // non-overlap pair letters
    int pairCount = 0;
    char prevPairChar = '\0';
    for (int i = 0; i < password.length() - 1; ++i) {
        if (password[i] == password[i + 1] && password[i] != prevPairChar) {
            pairCount++;
            prevPairChar = password[i];
            i++; 
        }
    }

    // forbidden letters
    bool notallowed = password.find("iol") == string::npos;
      // for (int i = 0; i < password.length() - 1; i++) {
    //     if ((str[i] == 'i' && str[i + 1] == 'b') ||
    //         (str[i] == 'o' && str[i + 1] == 'd') ||
    //         (str[i] == 'l' && str[i + 1] == 'q')) {
    //         notallowed = true;
    //         break;
    //     }
    // }
    //  if (password.find('i') != password.length() ||
    //     password.find('o') != password.length() ||
    //     password.find('l') != password.length()) {
    //         return false;
    // }
    return hasStraight && pairCount >= 2 && notallowed;
}

void incrementPassword(string &password) {
    int i = password.length() - 1;
    while (i >= 0) {
        if (password[i] != 'z') {
            password[i]++;
            break;
        } else {
            password[i] = 'a';
            i--;
        }
    }
}

int main() {
    string password = "hxbxxyzz";
    while (true) {
        incrementPassword(password);
        if (isValidPassword(password)) {
            break;
        }
    }




    cout << " next password is: " << password << endl;

    return 0;
}
