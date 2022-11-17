#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <fstream>

#include "omnidroids.hpp"
#include "robotomaton.hpp"

using namespace std;

int omnidroidsInput(ifstream &inputFile) {
    string numInput;
    string numOfParts;
    string numOfDependencies;

    getline(inputFile, numInput);
    int i;
    for(i=0; numInput[i]!=' '; i++) {
        numOfParts = numOfParts + numInput[i];
    } 
    for(; numInput[i]!='\n'; i++) {
        numOfDependencies = numOfDependencies + numInput[i];
    }
    int numParts = stoi(numOfParts);
    int numDependencies = stoi(numOfDependencies);

    part parts[numDependencies];
    int sprocketsPerPart[numParts];;
    int dependencyCount = 0;
    int partCount = 0;
    while(dependencyCount != numDependencies) {
        string input;
        string partI;
        string partJ;
        getline(inputFile, input);
        int j;
        for(j=0; input[j]!=' '; j++) {
            partI = partI + input[j];
        } 
        for(; input[j]!='\n'; j++) {
            partJ = partJ + input[j];
        }
        parts[dependencyCount].dependencyPart = stoi(partI);
        parts[dependencyCount].partToBuild = stoi(partJ);
        cout << parts[dependencyCount].dependencyPart << " " << parts[dependencyCount].partToBuild << endl;
        dependencyCount++;
    }
    while(partCount != numParts) {
        string numOfSprocketsUsed;
        getline(inputFile, numOfSprocketsUsed);
        sprocketsPerPart[partCount] = stoi(numOfSprocketsUsed);
        cout << sprocketsPerPart[partCount] << endl;
        partCount++;
    }

    int totalSprockets = omnidroids(parts, sprocketsPerPart, numParts, numDependencies);
    return totalSprockets;
}

int robotomatonInput(ifstream &inputFile) {
    string numOfStages;

    getline(inputFile, numOfStages);
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
    ifstream inputFile("input.txt");
    if(inputFile.is_open()) {
        string numOfRobots;
        string whiteSpace;
        string typeOfRobot;

        getline(inputFile, numOfRobots);
        getline(inputFile, whiteSpace);

        if(numOfRobots.compare("0") == 0) {
            printf("Please enter 1 or 2 to assemble robots.\n");
            return 0;
        } 
        else if(numOfRobots.compare("1") == 0) {
            getline(inputFile, typeOfRobot);
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
            getline(inputFile, typeOfRobot);
            if(typeOfRobot.compare("omnidroid") == 0) {
                int totalOmnidroidsSprockets = omnidroidsInput(inputFile);
                getline(inputFile, whiteSpace);
                getline(inputFile, typeOfRobot);
                int totalRobotomatonSprockets = robotomatonInput(inputFile);
                cout << "Expected result: 100 30" << endl;
                cout << "Actual result: " << totalOmnidroidsSprockets << " " << totalRobotomatonSprockets << endl;
            } 
            else if(typeOfRobot.compare("robotomaton") == 0) {
                int totalRobotomatonSprockets = robotomatonInput(inputFile);
                getline(inputFile, whiteSpace);
                getline(inputFile, typeOfRobot);
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