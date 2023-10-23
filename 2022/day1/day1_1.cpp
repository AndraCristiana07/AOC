#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
    auto in = ifstream("input.in");

    int curr = 0;
    int max_cal = 0;
    string tp;
    while (getline(in, tp)) { 
        printf("%ld\n", tp.length());
        if(tp.length() == 1) {

            // if(curr > max_cal) {
            //     max_cal = curr;
            // }
           
            max_cal = max(curr, max_cal);
            curr = 0;
            printf("%s\n", "ttt");
        }
       // printf("%s\n", tp.c_str());
        // curr += atoi(tp.c_str());
        //else{
            curr += atoi(tp.c_str());
        //}
    }
    in.close();
    // if(curr > max_cal) {
    //     max_cal = curr;
    // }
   

    max_cal = max(curr, max_cal);
    cout << max_cal << endl;
    // in.close();
    // auto out = ofstream("output.out");
    // out << max_cal << endl;
    // out.close();
    return 0;
}