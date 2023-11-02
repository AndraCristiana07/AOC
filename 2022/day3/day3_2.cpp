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
    char badge;
    auto in = ifstream("input.in");
    // string line; 
    string rucksack;
    vector<string> rucksacks,myChoices;
    while(in >> rucksack){
        rucksacks.push_back(rucksack);
    }


    in.close();
    for(int i=0; i<rucksacks.size(); i+=3){
       string r1 = rucksacks[i];
       string r2 = rucksacks[i+1];
       string r3 = rucksacks[i+2];

        for(int i=0; i< r1.size(); i++){
            char c1 = r1[i];
            for(int j=0; j< r2.size(); j++){
                char c2 = r2[j];
                for(int k=0; k< r3.size(); k++){
                    char c3 = r3[k];
                    if(c1 == c2 && c1 == c3)
                        priority= calcPriority(c1);
                }
            }
        }
        sum += priority;
        
        cout << "r1= " << r1 << endl;
        cout << "r2= " << r2 << endl;
        cout << "r3= " << r3 << endl;
        

        // cout << "mid sum:" << sum << endl;
        // cout << sum << endl;
    }
   

   cout << "Sum: " << sum << endl;
}