#include "omnidroids.hpp"

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