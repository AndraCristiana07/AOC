#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream in("input.in");
    

    string line;
    int totalPaper = 0;

    while (getline(in, line)) {
        istringstream iss(line);
        int l, w, h;
        char x;

        if (iss >> l >> x >> w >> x >> h) {
            int area1 = l * w;
            int area2 = w * h;
            int area3 = h * l;

            int extra = min({area1, area2, area3});
            int paper = 2 * area1 + 2 * area2 + 2 * area3 + extra;
            totalPaper += paper;
        }
    }

    cout << "totalPaper: " << totalPaper << endl;

    in.close();

    return 0;
}