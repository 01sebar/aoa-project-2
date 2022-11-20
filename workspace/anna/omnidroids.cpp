#include "omnidroids.hpp"

// Time complexity: O(m)
// Function that calculates the total sprockets needed to construc the given omniroid
int omnidroids(part* parts, int* sprocketsPerPart, int n, int m) {
    int sprocketsPerPartRunningTotal[n] = {0};          // Initialize array that keeps track of parts for parts to 0s
    for (int i = 0; i < m; i++) {
        int partToBuildId = parts[i].partToBuild;       //
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