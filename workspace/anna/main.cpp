#include <iostream>
#include <algorithm>
#include <string.h>
//#include <string>
#include <stdio.h>
#include <fstream>
//#include <cctype>

#include "omnidroids.hpp"
#include "robotomaton.hpp"

using namespace std;

// Function to input the information about omniroids 
int omnidroidsInput(ifstream &inputFile) {
    string numInput;
    string numOfParts;
    string numOfDependencies;
    string whiteSpace;

    getline(inputFile, whiteSpace);
    getline(inputFile, numInput, char(13));
    int i;
    for(i=0; numInput[i]!=' '; i++) {
        numOfParts = numOfParts + numInput[i];
    } 
    for(; numInput[i]!='\n'; i++) {
        numOfDependencies = numOfDependencies + numInput[i];
    }

    
    int numParts = stoi(numOfParts, nullptr, 10);
    //cout << numOfParts << endl;
    int numDependencies = stoi(numOfDependencies, nullptr, 10);
   // cout << numDependencies << endl;
    

    part parts[numDependencies];
    int sprocketsPerPart[numParts];;
    int dependencyCount = 0;
    int partCount = 0;
    // Creates list of parts that need other parts to be build
    while(dependencyCount != numDependencies) {
        
        string input;
        string partI;
        string partJ;
        string whitespace;

        // Gets one line with 2 numbers
        getline(inputFile, input , char(13));
        getline(inputFile, whitespace);
        // Identifies i and j
        int j;
        for(j=0; input[j]!=' '; j++) {
            partI = partI + input[j];
        } 
        for(; input[j]!='\n'; j++) {
            partJ = partJ + input[j];
        }
        // Parts that are build on dependencies: i is used in assembly of part j
        parts[dependencyCount].dependencyPart = stoi(partI, nullptr, 10);
        parts[dependencyCount].partToBuild = stoi(partJ, nullptr, 10);
        //cout << parts[dependencyCount].dependencyPart << " " << parts[dependencyCount].partToBuild << endl;
        dependencyCount++;
    }
    //Creates a list of sprockets used per part
    while(partCount != numParts) {
        string numOfSprocketsUsed;
        getline(inputFile, numOfSprocketsUsed);
        sprocketsPerPart[partCount] = stoi(numOfSprocketsUsed, nullptr, 10);
        cout << sprocketsPerPart[partCount] << endl;
        partCount++;
    }

    int totalSprockets = omnidroids(parts, sprocketsPerPart, numParts, numDependencies);
    return totalSprockets;
}

// Function to input the information about robotomaton
int robotomatonInput(ifstream &inputFile) {
    string numOfStages;
    string whiteSpace;

    getline(inputFile, whiteSpace);
    getline(inputFile, numOfStages);
    cout << numOfStages<< endl;
    int numStages = stoi(numOfStages);

    stage stages[numStages];
    int count = 0;
    while(count != numStages) {
        string input;
        string sprockets;
        string prevStages;
        getline(inputFile, input);
        int i;
        for(i=0; input[i]!=' '; i++) {
            sprockets = sprockets + input[i];
        } 
        for(; input[i]!='\n'; i++) {
            prevStages = prevStages + input[i];
        }
        stages[count].s = stoi(sprockets);
        stages[count].p = stoi(prevStages);
        count++;
    }
    int totalSprockets = robotomaton(stages, numStages);
    return totalSprockets;
}

int main() {
    // Creates stream to file destination
    ifstream inputFile("input.txt");
    // Reads the file if it is opened succesfully
    if(inputFile.is_open()) {
        std::string numOfRobots;
        std::string whiteSpace;
        std::string typeOfRobot;

        // Gets the number of robots on the first line and the next whitespace
        getline(inputFile, numOfRobots, char(13));
        getline(inputFile, whiteSpace, char(13));

        // Depending on how many robots are specified the input differs
        if(numOfRobots.compare("0") == 0) {
            cout << "Please enter 1 or 2 to assemble robots."<< endl;
            return 0;
        } 
        // If 1 robot specified: reads the type of robot and then reads and executes calculations for the robot
        else if(numOfRobots.compare("1") == 0) {
            getline(inputFile, whiteSpace);
            getline(inputFile, typeOfRobot, char(13));
            if(typeOfRobot.compare("omnidroid") == 0) {
                int totalSprockets = omnidroidsInput(inputFile);
                cout << "Expected result: 51" << endl;
                cout << "Actual result: " << totalSprockets << endl;
            } 
            else if(typeOfRobot.compare("robotomaton") == 0) {
                int totalSprockets = robotomatonInput(inputFile);
                cout << "Expected result: 143" << endl;
                cout << "Actual result: " << totalSprockets << endl;
            } 
        }
        else if(numOfRobots.compare("2") == 0) {
            getline(inputFile, whiteSpace);
            getline(inputFile, typeOfRobot, char(13));
            
            if(typeOfRobot.compare("omnidroid") == 0) {
                int totalOmnidroidsSprockets = omnidroidsInput(inputFile);
                getline(inputFile, whiteSpace);
                getline(inputFile, typeOfRobot, char(13));
                int totalRobotomatonSprockets = robotomatonInput(inputFile);
                cout << "Expected result: 100 30" << endl;
                cout << "Actual result: " << totalOmnidroidsSprockets << " " << totalRobotomatonSprockets << endl;
            } 
            else if(typeOfRobot.compare("robotomaton") == 0) {
                int totalRobotomatonSprockets = robotomatonInput(inputFile);
                getline(inputFile, whiteSpace);
                getline(inputFile, typeOfRobot, char(13));
                int totalOmnidroidsSprockets = omnidroidsInput(inputFile);
                cout << "Expected result: 30 100" << endl;
                cout << "Actual result: " << totalRobotomatonSprockets << " " << totalOmnidroidsSprockets << endl;
            } 
        } 
    } 
    inputFile.close();

    return 0;
    // expected output: 100 30
}