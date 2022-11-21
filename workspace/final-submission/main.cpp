#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <fstream>

#include "omnidroids.hpp"
#include "robotomaton.hpp"

using namespace std;

// Function to input the information about omniroids 
int omnidroidsInput(ifstream &inputFile) {
    cout << "omnidroids" << endl;
    string numInput;
    string numOfParts;
    string numOfDependencies;

    getline(inputFile, numInput, char(13));

    int i;
    for(i=0; numInput[i]!=' '; i++) {
        numOfParts = numOfParts + numInput[i];
    } 
    for(; numInput[i]!='\n'; i++) {
        numOfDependencies = numOfDependencies + numInput[i];
    }

    
    int numParts = stoi(numOfParts, nullptr, 10);
    int numDependencies = stoi(numOfDependencies, nullptr, 10);
    
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
        dependencyCount++;
    }

    //Creates a list of sprockets used per part
    while(partCount != numParts) {
        string numOfSprocketsUsed;
        getline(inputFile, numOfSprocketsUsed);
        sprocketsPerPart[partCount] = stoi(numOfSprocketsUsed, nullptr, 10);
        partCount++;
    }

    int totalSprockets = omnidroids(parts, sprocketsPerPart, numParts, numDependencies);
    return totalSprockets;
}

// Function to input the information about robotomaton
int robotomatonInput(ifstream &inputFile) {
    cout << "robotomaton" << endl;
    string numOfStages;
    string whitespace;

    getline(inputFile, numOfStages, char(13));
    int numStages = stoi(numOfStages, nullptr, 10);

    stage stages[numStages];
    int count = 0;
    while(count < numStages) {
        string input;
        string sprockets;
        string prevStages;

        getline(inputFile, input, char(13));
        int i;
        for(i=0; input[i]!=' '; i++) {
            sprockets = sprockets + input[i];
        } 
        for(; input[i]!='\n'; i++) {
            prevStages = prevStages + input[i];
        }
        stages[count].s = stoi(sprockets, nullptr, 10);
        stages[count].p = stoi(prevStages, nullptr, 10);
        count++;
    }
    getline(inputFile, whitespace);

    int totalSprockets = robotomaton(stages, numStages);
    return totalSprockets;
}

int main() {
    // Creates stream to file destination
    ifstream inputFile("input.txt");
    ofstream outFile;
    outFile.open("output.txt");
    // Reads the file if it is opened succesfully
    if(inputFile.is_open()) {
        string numOfRobots;
        string whiteSpace;
        string typeOfRobot;

        // Gets the number of robots on the first line and the next whitespace
        getline(inputFile, numOfRobots, char(13));
        getline(inputFile, whiteSpace);
        int numRobots = stoi(numOfRobots, nullptr, 10);

        // Depending on how many robots are specified the input differs
        if(numRobots == 0) {
            cout << "Please enter 1 or 2 to assemble robots."<< endl;
            return 0;
        } 

        for(int i=0; i<numRobots; i++) {
            cout << i << endl;

            getline(inputFile, whiteSpace);
            getline(inputFile, typeOfRobot, char(13));
            cout << typeOfRobot << endl;
            if(typeOfRobot.compare("omnidroid") == 0) {
                int totalSprockets = omnidroidsInput(inputFile);
                outFile << totalSprockets << endl;
            } 
            else if(typeOfRobot.compare("robotomaton") == 0) {
                int totalSprockets = robotomatonInput(inputFile);
                outFile << totalSprockets << endl;
            } 
        } 
    } 
    inputFile.close();
    outFile.close();

    return 0;
}