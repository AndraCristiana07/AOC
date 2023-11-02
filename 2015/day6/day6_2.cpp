#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream in("input.in");
    
    string line;
    vector<vector<int>> grid(1000, vector<int>(1000, 0));
    int brightness = 0;

    while (getline(in, line)) {
        replace(line.begin(), line.end(), ',', ' ');

        istringstream iss(line);
        string action;
        string setting;
        int x1, y1, x2, y2;
        string t;

        iss >> action;
        if (action == "turn") {
            iss >> setting >> x1 >> y1 >> t >> x2 >> y2;
        } else if (action == "toggle"){
            iss >> x1 >> y1 >> t >> x2 >> y2;
        }

        for (int x = x1; x <= x2; x++) {
            for (int y = y1; y <= y2; y++) {
                if (action == "turn") {
                    iss >> setting; 
                    if (setting == "on") {
                        grid[x][y] += 1;
                    } else if (setting == "off") {
                        grid[x][y] = max(0, grid[x][y] - 1);
                    }
                } else if (action == "toggle") {
                    grid[x][y] += 2;
                }
            }
        }
    }

    for (int x = 0; x < 1000; x++) {
        for (int y = 0; y < 1000; y++) {
            if (grid[x][y]) {
                brightness += grid[x][y];
            }
        }
    }

    cout << "brightness: " << brightness << endl;

    in.close();

    return 0;
}
