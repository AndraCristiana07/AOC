#include <fstream>
#include <iostream>
#include <string>
#include <algorithm> 

using namespace std;

int main() {
    auto in = ifstream("input.in");
    vector<int> calories;
    string tp;
    int sum = 0;
    while (getline(in, tp)) {
        if(tp.length() == 1) {
            calories.push_back(sum);
            sum = 0;
        } else {
            sum += atoi(tp.c_str());
        }
    }
    sort(calories.rbegin(), calories.rend());
    int total_calories = 0;
    for (int i = 0; i < 3 && i < calories.size(); i++) {
        total_calories += calories[i];
    }
    cout << total_calories << endl;
    return 0;
}