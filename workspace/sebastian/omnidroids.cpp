#include <iostream>

struct part {
    int dependencyPart;
    int partToBuild;
};

int omnidroids(part* parts, int* sprocketsPerPart, int n, int m);

int main() {
    // TODO implement file reading to create following data structs
    int n = 8;
    int m = 12;
    int sprocketsPerPart[] = {4, 2, 6, 24, 14, 5, 3, 6}; // length of this will be n

    // 0 1
    part part1;
    part1.dependencyPart = 0;
    part1.partToBuild = 1;
    // 0 1
    part part2;
    part2.dependencyPart = 0;
    part2.partToBuild = 1;
    // 0 2
    part part3;
    part3.dependencyPart = 0;
    part3.partToBuild = 2;
    // 0 2
    part part4;
    part4.dependencyPart = 0;
    part4.partToBuild = 2;
    // 4 6
    part part5;
    part5.dependencyPart = 4;
    part5.partToBuild = 6;
    // 5 6
    part part6;
    part6.dependencyPart = 5;
    part6.partToBuild = 6;
    // 1 7
    part part7;
    part7.dependencyPart = 1;
    part7.partToBuild = 7;
    // 1 7
    part part8;
    part8.dependencyPart = 1;
    part8.partToBuild = 7;
    // 2 7
    part part9;
    part9.dependencyPart = 2;
    part9.partToBuild = 7;
    // 2 7
    part part10;
    part10.dependencyPart = 2;
    part10.partToBuild = 7;
    // 3 7
    part part11;
    part11.dependencyPart = 3;
    part11.partToBuild = 7;
    // 6 7
    part part12;
    part12.dependencyPart = 6;
    part12.partToBuild = 7;

    part parts[] = {part1, part2, part3, part4, part5, part6, part7, part8, part9, part10, part11, part12};
    int totalSprockets = omnidroids(parts, sprocketsPerPart, n, m);
    std::cout << "Expected result: 100" << std::endl;
    std::cout << "Actual result: " << totalSprockets << std::endl;
    return 0;
}

// Time complexity: O(m)
int omnidroids(part* parts, int* sprocketsPerPart, int n, int m) {
    int sprocketsPerPartRunningTotal[n] = {0};
    for (int i = 0; i < m; i++) {
        int partToBuildId = parts[i].partToBuild;
        int dependencyId = parts[i].dependencyPart;
        if(sprocketsPerPartRunningTotal[partToBuildId] == 0) {
            sprocketsPerPartRunningTotal[partToBuildId] = sprocketsPerPart[partToBuildId];
        }
        // This will be true when using a prim part to construct the current partToBuildId
        if(sprocketsPerPartRunningTotal[dependencyId] == 0) {
            sprocketsPerPartRunningTotal[partToBuildId] += sprocketsPerPart[dependencyId];
        } else {
            sprocketsPerPartRunningTotal[partToBuildId] += sprocketsPerPartRunningTotal[dependencyId];
        }
    }
    int totalSprockets = sprocketsPerPartRunningTotal[n - 1];
    return totalSprockets;
}