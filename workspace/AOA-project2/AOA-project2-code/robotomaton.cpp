#include "robotomaton.hpp"

// Inputs:
// stages: reference to array of stages
// n: count of stages
// Output:
// totalSprockets: final count of sprockets needed to construct robotomaton with given params
// Complexity: O(nlgn)
int robotomaton_wrapper(stage* stages, int n) {
    // memoization data structure initialized with -1
    int sprocketsPerStep[n];
    for (int i = 0; i < n; i++) {
        sprocketsPerStep[i] = -1;
    }

    int totalSprockets = robotomaton_recursive(stages, n - 1, sprocketsPerStep);

    return totalSprockets;
}

int robotomaton_recursive(stage* stages, int n, int* sprocketsPerStep) {
    if(sprocketsPerStep[n] != -1) {
        return sprocketsPerStep[n];
    }
    // based case for primitive part
    if(stages[n].p == 0) {
        sprocketsPerStep[n] = stages[n].s;
        return sprocketsPerStep[n];
    } else {
        sprocketsPerStep[n] = stages[n].s;
        int prevStage = stages[n].p;
        // iterate from right before current stage and iterate backwards (i - stages[i].p) times
        for(int j = n - 1; prevStage > 0; j--) {
            sprocketsPerStep[n] = sprocketsPerStep[n] + robotomaton_recursive(stages, j, sprocketsPerStep);
            prevStage--;    
        }

        return sprocketsPerStep[n];
    }
}