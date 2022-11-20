#include "omnidroids.hpp"

// Inputs:
// parts: Reference to array of parts
// n: Count of stages
// m: Count of assembly dependencies
// Output:
// sprocketsPerPartRunningTotal: final count of sprockets needed to construct omnidroids with given params
// Time complexity: O(m)
int omnidroids(part* parts, int* sprocketsPerPart, int n, int m) {
    int sprocketsPerPartRunningTotal[n] = {0};          // Initialize array that keeps track of parts for parts to 0s
    for (int i = 0; i < m; i++) {
        int partToBuildId = parts[i].partToBuild;
        int dependencyId = parts[i].dependencyPart;
        // Assigns the number needs to build each part
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