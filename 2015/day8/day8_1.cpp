#include <bits/stdc++.h>
using namespace std;


int countCodeMinusMemory(string line) {
    int codeLength = line.length();
    int memoryLength = 0;

    for (int i = 1; i < line.length() - 1; i++) {
        if (line[i] == '\\') {
            i++; // backslash 
            if (line[i] == '\\' || line[i] == '"') {
                memoryLength++;
            } else if (line[i] == 'x') {
                // hexadecimal
                i += 2; 
                memoryLength++;
            }
        } else {
            memoryLength++;
        }
    }

    return codeLength - memoryLength;
}

int main() {
    ifstream input("input.in");
    string line;
    int totalDifference = 0;

    while (getline(input, line)) {
        int difference = countCodeMinusMemory(line);
        totalDifference += difference;
    }

    input.close();

    cout << "difference: " << totalDifference << endl;

    return 0;
}
