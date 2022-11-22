#include "robotomaton.hpp"

// Inputs:
// stages: Reference to array of stages
// n: Count of stages
// Output:
// totalSprockets: final count of sprockets needed to construct robotomaton with given params
// Complexity: O(nlgn)
int robotomaton_wrapper(stage* stages, int n) {
    // Data Structure is initialized and all values are set to -1
    int sprocketsPerStep[n] = {0};
    for (int i = 0; i < n; i++) {
        sprocketsPerStep[i] = -1;
    }

    int totalSprockets = robotomaton_recursive(stages, n - 1 , sprocketsPerStep);
    return totalSprockets;
}

int robotomaton_recursive(stage* stages, int n, int sprocketsPerStep[]) {
    if (sprocketsPerStep[n] != -1) {
        return sprocketsPerStep[n];
    }
    else if (stages[n].p = 0){
        sprocketsPerStep[n] = stages[n].s;
        return sprocketsPerStep[n];
    }
    else{
        sprocketsPerStep[n] = stages[n].s;
        int stage = stages[n-1].p;
        for (int j = n - 1; stage != -1; j--){
            sprocketsPerStep[n] = sprocketsPerStep[n] + robotomaton_recursive(stages, j, sprocketsPerStep);
            stage --;    
        }

        return sprocketsPerStep[n];
    }
}