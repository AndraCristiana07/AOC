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
        int pos1, pos2;
        char letter, col;
        string password;
        iss >> pos1 >> col >> pos2  >> letter >> col >> password;
        
        pos1--;
        pos2--;

        if ((password[pos1] == letter) != (password[pos2] == letter)) {
            validCount++;
        }
    }

    cout << "Pass: " << validCount << endl;
    return 0;
}
