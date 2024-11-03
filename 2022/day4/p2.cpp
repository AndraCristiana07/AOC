#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main() {
   
    auto in = ifstream("input.in");
    int overlap = 0;
    string space;
    vector<string> areas;
    while(in >> space){
        areas.push_back(space);
    }

    in.close();

     for(int i=0; i<areas.size(); i++){
        string space = areas[i];
       
        string elf1 = space.substr(0, space.find(','));
        string elf2 = space.substr(space.find(',') + 1);

        int range1Start = stoi(elf1.substr(0, elf1.find('-')));
        int range1End = stoi(elf1.substr(elf1.find('-') + 1));

        int range2Start = stoi(elf2.substr(0, elf2.find('-')));
        int range2End = stoi(elf2.substr(elf2.find('-') + 1));

        cout << "range1: " << range1Start << "-" << range1End << endl;
        cout << "range2: " << range2Start << "-" << range2End << endl;

        if(range1End >= range2Start && range2End >= range1Start)
                overlap++;

     }

   cout << "overlap: " << overlap << endl;
}