#ifndef __OMNIDROIDS_HPP_
#define __OMNIDROIDS_HPP_

#include <iostream>
#include <queue>

struct part {
    int dependencyPart;
    int partToBuild;
};

int omnidroids_wrapper(std::queue<part> partsStack, int* sprocketsPerPart, int n);
void omnidroids_recursive(std::queue<part> partsStack, int* sprocketsPerPart, int* sprocketsPerPartRunningTotal);

#endif