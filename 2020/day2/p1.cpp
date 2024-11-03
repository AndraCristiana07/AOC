#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    ifstream inputFile("input.in");
    int validCount = 0;
    string line;

    while (getline(inputFile, line)) {
        istringstream iss(line);
        int first, second;
        char letter, col;
        string password;
        iss >> first >> col >> second  >> letter >> col >> password;
        // cout << first <<  endl;
        // cout << password << endl;
        int letterCount = 0;
        for(int i=0; i<password.size(); i++) {
            if(password[i] == letter)
                letterCount++;
        }
        if (letterCount >= first && letterCount <= second) {
            validCount++;
        }
    }

    cout << "Nr of pass: " << validCount << endl;
    return 0;
}
