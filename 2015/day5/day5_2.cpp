#include <bits/stdc++.h>
using namespace std;


bool isNiceString(string str) {
    

    //1
    bool hasPair = false;
    //  unordered_set<string> pairs; 

    for (size_t i = 0; i < str.length()-2; i++) {
        string pair = str.substr(i, 2);
        // if (pairs.find(pair) != pairs.end()) {
        //     hasPair = true;
        //     break;
        // }
        // pairs.insert(pair);

        size_t found = str.find(pair, i + 2);
        if (found != string::npos) {
           hasPair = true;
        }
        // while(find(str.begin(), str.end(), found) == str.end()) {
        //    hasPair = true;
        // }
        // vector<string> s;
        // s.push_back(str);
        // vector<size_t> letters;
        // letters.push_back(found);
    //    if (find(letters.begin(), letters.end(), found) != letters.end()) {
    //         hasPair = true;
    //     }
    // if (s[i].find(found)) {
    //        hasPair = true;
    //     }

        // string pairs;
        // if (str[i] == str[i + 1]) {
        //     if (pairs.empty() || pairs.back() != str[i]) {
        //         pairs += str[i];
        //          hasPair = true;
        //     }
        // }
    }
    
    //2
    bool repeat = false;
    for (int i = 0; i < str.length() - 1; i++) {
        if (str[i] == str[i + 2]) {
            repeat = true;
            break;
        }
    }

    return hasPair && repeat;
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