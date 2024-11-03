#include <bits/stdc++.h>
using namespace std;


int countCodeMinusMemory(string line) {
    int codeLength = line.length();
    int encodedLength = 2; 

    for (int i = 0; i < line.length(); i++) {
        
        if (line[i] == '\\' || line[i] == '"') {
            encodedLength += 2;
        } else {
            encodedLength++;
        }
    }

    return encodedLength - codeLength;
}

int main() {
    ifstream input("input.in");
    string line;
    int totalDifference = 0;

    while (getline(input, line)) {
        int difference = countCodeMinusMemory(line);
        cout << "difference: " << difference << endl;
        totalDifference += difference;
    }

    input.close();

    cout << "difference: " << totalDifference << endl;

    return 0;
}
