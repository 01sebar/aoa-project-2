#include "robotomaton.hpp"

// Inputs:
// stages: Reference to array of stages
// n: Count of stages
// Output:
// totalSprockets: final count of sprockets needed to construct robotomaton with given params
// Complexity: O(nlgn)
int robotomaton(stage* stages, int n) {
    // memoization data structure initialized with 0
    int sprocketsPerStep[n] = {0};
    for (int i = 0; i < n; i++) {
        sprocketsPerStep[i] = stages[i].s;
        // based case for primitive part
        if(stages[i].p == 0) {
            // std::cout << "stage " << i << " does not have previous steps involved" << std::endl;
            continue;
        };
        // iterate from right before current stage and iterate backwards (i - stages[i].p) times
        for (int j = i - 1; j >= i - stages[i].p; j--) {
            sprocketsPerStep[i] += sprocketsPerStep[j];
        }
    }
    // Get last item in sprocketsPerStep array
    int totalSprockets = sprocketsPerStep[n - 1];
    return totalSprockets;
}