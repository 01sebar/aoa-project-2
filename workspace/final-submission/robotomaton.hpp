#ifndef __ROBOTOMATON_HPP_
#define __ROBOTOMATON_HPP_

#include <iostream>

struct stage {
    int s; // sprockets
    int p; // previous stages needed
};

int robotomaton(stage* stages, int n);
int RecRobotomaton(stage* stages, int n, int sprocketsPerStep[]);

#endif