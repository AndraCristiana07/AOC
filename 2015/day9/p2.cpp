#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream in("input.in");
   

    string line;
    int totalRibbon = 0;

    while (getline(in, line)) {
        istringstream iss(line);
        int l, w, h;
        char x;

        if (iss >> l >> x >> w >> x >> h) {
            int peri = 2*l + 2*w + 2*h - 2*max({l,w,h});
            int bow = l * w * h;
            totalRibbon += peri + bow;
        }
    }
    
    cout << "ribbon: " << totalRibbon << endl;

    in.close();

    return 0;
}
