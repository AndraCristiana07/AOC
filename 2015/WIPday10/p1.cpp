#include <bits/stdc++.h>

using namespace std;

string lookAndSay(string str){
    string resultString;
    int i=0;
    while(i < str.length()){
        int count = 0;
        while(i < str.length()-1 && str[i] == str[i+1]){
            count++;
            i++;
        }
        resultString += to_string(count) + str[i];
    }
    return resultString;
}

int main() {
    string in = "1211";
    string resultString;
    for(int i=0; i< in.length(); i++){
        resultString = lookAndSay(in);
    }

    cout << "transf: " << resultString.length() << endl;


    return 0;
}