#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int calcPriority(char c){
    if(c >= 'a' && c <= 'z')
        return c - 'a' + 1;
    else if(c >= 'A' && c<= 'Z')
        return c - 'A' + 26 + 1;
    return 0;
}
int main() {
    int sum=0;
    int priority;
    auto in = ifstream("input.in");
    // string line; 
    string rucksack;
    vector<string> rucksacks,myChoices;
    while(in >> rucksack){
        rucksacks.push_back(rucksack);
    }


    in.close();
    for(int i=0; i<rucksacks.size(); i++){
        string rucksack = rucksacks[i];
        int half = rucksack.size() / 2;
        string cp1 = rucksack.substr(0, half);
        string cp2 = rucksack.substr(half);

        for(int i=0; i< cp1.size(); i++){
            char c1 = cp1[i];
            for(int j=0; j< cp2.size(); j++){
                char c2 = cp2[j];
                if(c1 == c2)
                    priority= calcPriority(c1);
            }
        }
        sum += priority;
        
        cout << "cp1= " << cp1 << endl;
        cout << "cp2= " << cp2 << endl;

        cout << "mid sum:" << sum << endl;
        // cout << sum << endl;
    }
   

   cout << "Sum: " << sum << endl;
}