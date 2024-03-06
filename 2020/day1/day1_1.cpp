#include <iostream>
#include <fstream>
#include <unordered_set>
#include <vector>

using namespace std;

int findProduct(vector<int>& numbers) {
    unordered_set<int> seen;

    for (int nr1 : numbers) {
        int nr2 = 2020 - nr1;
        if (seen.find(nr2) != seen.end()) {
            return nr1 * nr2;
        }
        seen.insert(nr1);
    }

    return -1;
}

int main() {
    ifstream inputFile("input.in");

    vector<int> numbers;
    int nr;
    while (inputFile >> nr) {
        numbers.push_back(nr);
    }
    inputFile.close();

    int product = findProduct(numbers);
        cout << "Product : " << product << endl;
   

    return 0;
}
