#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main() {
    auto in = ifstream("input.in");
    

    string instructions;
    in >> instructions; 

    int floor = 0; 

     for (int position = 0; position < instructions.size(); position++) {
        char instruction = instructions[position];
        if (instruction == '(') {
            floor++; 
        } else if (instruction == ')') {
            floor--; 
        }

        if (floor == -1) {
            cout << "position " << position + 1 << endl;
            break; 
        }
    }

    in.close(); 

    return 0;
}
