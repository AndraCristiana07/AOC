#include <bits/stdc++.h>
using namespace std;

int countHousesWithPresents(string &directions) {
    int x = 0, y = 0;
    set<pair<int, int>> visitedHouses;
    visitedHouses.insert(make_pair(x, y));

    char direction;
    for (int i = 0; i < directions.length(); i++) {
        direction = directions[i];
        if (direction == '>') {
            x++;
        } else if (direction == '<') {
            x--;
        } else if (direction == '^') {
            y++;
        } else if (direction == 'v') {
            y--;
        }
        
        visitedHouses.insert(make_pair(x, y));
    }

    return visitedHouses.size();
}

int main() {
    auto in = ifstream("input.in");
    string directions;

    in >> directions; 
    int houses = countHousesWithPresents(directions);
    cout << houses << endl;
    return 0;
}
