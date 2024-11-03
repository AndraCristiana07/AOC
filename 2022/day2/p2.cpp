#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int calc(vector<char> opChoices,vector<char> myChoices){
    int score = 0;
    char choices[] = {'X','Y','Z'};
    for(int i=0; i< opChoices.size(); i++){
        char opChoice = opChoices[i];
        char ending= myChoices[i];

        // int myScore;
        // if(ending== 'X')
        //     myScore = 1;
        // else if(ending== 'Y')
        //     myScore = 2;
        // else if(ending== 'Z')
        //     myScore = 3;
    
        int roundScore;
        if(opChoice == 'A'){
            if(ending== 'X')
                roundScore = 0 + 3; // lose
            else if(ending== 'Y')
                roundScore = 3 + 1; // draw
            else if(ending== 'Z')
                roundScore = 6 + 2; // win
        }
        else if(opChoice == 'B'){
            if(ending== 'X')
                roundScore = 0 + 1; // lose
            else if(ending== 'Y')
                roundScore = 3 + 2; // draw
            else if(ending== 'Z')
                roundScore = 6 + 3; // win
        }
        else if(opChoice == 'C'){
            if(ending== 'X')
                roundScore = 0 + 2; // lose
            else if(ending== 'Y')
                roundScore = 3 + 3; // draw
            else if(ending== 'Z')
                roundScore = 6 + 1; // win
        }
        score +=  roundScore;
    }
    return score;
}
int main() {
    auto in = ifstream("input.in");
    // string line; 
    char opChoice, myChoice;
    vector<char> opChoices,myChoices;
    while(in >> opChoice >> myChoice){
        opChoices.push_back(opChoice);
        myChoices.push_back(myChoice);
    }


    in.close();
    int score = calc(opChoices, myChoices);
   

   cout << "Total Score: " << score << endl;
}