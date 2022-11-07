#include <iostream>

struct stage {
    int s; // sprockets
    int p; // previous stages needed
};

int robotomaton(stage* stages, int n);

int main() {
    // TODO: Implement file reading
    int n = 5;
    stage stage1;
    stage1.s = 3;
    stage1.p = 0;
    stage stage2;
    stage2.s = 11;
    stage2.p = 0;
    stage stage3;
    stage3.s = 31;
    stage3.p = 1;
    stage stage4;
    stage4.s = 29;
    stage4.p = 2;
    stage stage5;
    stage5.s = 5;
    stage5.p = 4;

    stage stages[5] = { stage1, stage2, stage3, stage4, stage5 };
    int totalSprockets = robotomaton(stages, n);
    std::cout << "Expected result: 143" << std::endl;
    std::cout << "Actual result: " << totalSprockets << std::endl;
    return 0;
}


// Inputs:
// stages: Reference to array of stages
// n: Count of stages
// Output:
// totalSprockets: final count of sprockets needed to construct robotomaton with given params
int robotomaton(stage* stages, int n) {
    // memoization data structure initialized with 0
    int sprocketsPerStep[n];
    for (int i = 0; i < n; i++) {
        sprocketsPerStep[i] = stages[i].s;
        // based case for primitive part
        if(stages[i].p == 0) {
            // std::cout << "stage " << i << " does not have previous steps involved" << std::endl;
            std::cout << "sprockets needed for stage " << i << " is: " << sprocketsPerStep[i] << std::endl;
            continue;
        };
        // iterate from right before current stage and iterate backwards (i - stages[i].p) times
        for (int j = i - 1; j >= i - stages[i].p; j--) {
            sprocketsPerStep[i] += sprocketsPerStep[j];
        }
        std::cout << "sprockets needed for stage " << i << " is: " << sprocketsPerStep[i] << std::endl;
    }
    // Get last item in sprocketsPerStep array
    int totalSprockets = sprocketsPerStep[n - 1];
    return totalSprockets;
}