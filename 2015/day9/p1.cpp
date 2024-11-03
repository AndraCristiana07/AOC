#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream in("input.in");
   
    map<pair<string, string>, int> distances;
    string line;
    int minDist = 100000;
    while (getline(in, line)) {
        istringstream iss(line);
        string loc1, loc2, to, eq;
        int distance;

        while(iss >> loc1 >> to >> loc2 >> eq >> distance){
            distances[{loc1, loc2}] = distance;
            distances[{loc2, loc1}] = distance;
        }
           
        vector<string> locations;
        for(auto loc: distances){
            locations.push_back(loc.first.first);
            locations.push_back(loc.first.second);
        }
    }

   

    cout << "shortest distance: " << minDist << endl;

    return 0;
}
