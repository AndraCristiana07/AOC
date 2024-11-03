#include <bits/stdc++.h>
using namespace std;

int countHousesWithPresents(string &directions) {
    int xSanta = 0, ySanta = 0;
    int xRobo = 0, yRobo = 0;
    
    set<pair<int, int>> visitedHouses;
    visitedHouses.insert(make_pair(xSanta, ySanta));

    char direction;
    for (int i = 0; i < directions.length(); i++) {
        direction = directions[i];
            if(i%2 == 0){
                if (direction == '>') {
                    xSanta++;
                } else if (direction == '<') {
                    xSanta--;
                } else if (direction == '^') {
                    ySanta++;
                } else if (direction == 'v') {
                    ySanta--;
                }
                visitedHouses.insert(make_pair(xSanta, ySanta));

            } else {
                if (direction == '>') {
                    xRobo++;
                } else if (direction == '<') {
                    xRobo--;
                } else if (direction == '^') {
                    yRobo++;
                } else if (direction == 'v') {
                    yRobo--;
                }
                visitedHouses.insert(make_pair(xRobo, yRobo));

            }
       
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
