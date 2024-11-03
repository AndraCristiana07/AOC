#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main() {
    auto in = ifstream("input.in");
    

    string instructions;
    in >> instructions; 

    int floor = 0; 

    for (char instruction : instructions) {
        if (instruction == '(') {
            floor++; 
        } else if (instruction == ')') {
            floor--; 
        }
    }

    cout << "floor " << floor << endl;

    in.close(); 

    return 0;
}
