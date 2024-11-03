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
        char myChoice = myChoices[i];

        int myScore;
        if(myChoice == 'X')
            myScore = 1;
        else if(myChoice == 'Y')
            myScore = 2;
        else if(myChoice == 'Z')
            myScore = 3;
    
        int roundScore;
        if(opChoice == 'A'){
            if(myChoice == 'X')
                roundScore = 3; // draw
            else if(myChoice == 'Y')
                roundScore = 6; // win
            else if(myChoice == 'Z')
                roundScore = 0; // lose
        }
        else if(opChoice == 'B'){
            if(myChoice == 'X')
                roundScore = 0; // lose
            else if(myChoice == 'Y')
                roundScore = 3; // draw
            else if(myChoice == 'Z')
                roundScore = 6; // win
        }
        else if(opChoice == 'C'){
            if(myChoice == 'X')
                roundScore = 6; // win
            else if(myChoice == 'Y')
                roundScore = 0; // lose
            else if(myChoice == 'Z')
                roundScore = 3; // draw
        }
        score += myScore + roundScore;
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