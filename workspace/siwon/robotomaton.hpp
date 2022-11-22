#ifndef __ROBOTOMATON_HPP_
#define __ROBOTOMATON_HPP_

#include <iostream>

struct stage {
    int s; // sprockets
    int p; // previous stages needed
};

int robotomaton_wrapper(stage* stages, int n);
int robotomaton_recursive(stage* stages, int n, int* sprocketsPerStep);

#endif