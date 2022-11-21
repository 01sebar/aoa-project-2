#include "omnidroids.hpp"

// Inputs:
// parts: Reference to queue of parts
// n: Count of stages
// Output:
// sprocketsPerPartRunningTotal: final count of sprockets needed to construct omnidroids with given params
// Time complexity: O(m)
int omnidroids_wrapper(std::queue<part> partsStack, int* sprocketsPerPart, int n) {
    int* sprocketsPerPartRunningTotal = new int[n];
    omnidroids_recursive(partsStack, sprocketsPerPart, sprocketsPerPartRunningTotal);
    int totalSprockets = sprocketsPerPartRunningTotal[n - 1];
    delete[] sprocketsPerPartRunningTotal;
    return totalSprockets;
}

void omnidroids_recursive(std::queue<part> partsStack, int* sprocketsPerPart, int* sprocketsPerPartRunningTotal) {
    part tempPart = partsStack.front();
    partsStack.pop();
    int partToBuildId = tempPart.partToBuild;
    int dependencyId = tempPart.dependencyPart;
    if(sprocketsPerPartRunningTotal[partToBuildId] == 0) {
        sprocketsPerPartRunningTotal[partToBuildId] = sprocketsPerPart[partToBuildId];
    }
    // This will be true when using a prim part to construct the current partToBuildId
    if(sprocketsPerPartRunningTotal[dependencyId] == 0) {
        sprocketsPerPartRunningTotal[partToBuildId] += sprocketsPerPart[dependencyId];
    } else {
        sprocketsPerPartRunningTotal[partToBuildId] += sprocketsPerPartRunningTotal[dependencyId];
    }

    if(partsStack.size() != 0) {
        omnidroids_recursive(partsStack, sprocketsPerPart, sprocketsPerPartRunningTotal);
    }
    return;
}