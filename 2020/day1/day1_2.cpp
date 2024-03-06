#include <iostream>
#include <fstream>
#include <unordered_set>
#include <vector>

using namespace std;

int findProduct(vector<int>& numbers) {
    unordered_set<int> seen;

    for (int nr1 : numbers) {
        for(int nr2 : numbers) {
            int nr3 = 2020 - nr1 - nr2;
            if (seen.find(nr3) != seen.end()) {
                return nr1 * nr2 * nr3;
            }
            seen.insert(nr2);
            
        }
       
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
