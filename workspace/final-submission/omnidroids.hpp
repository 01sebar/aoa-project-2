#ifndef __OMNIDROIDS_HPP_
#define __OMNIDROIDS_HPP_

#include <iostream>

struct part {
    int dependencyPart;
    int partToBuild;
};

int omnidroids(part* parts, int* sprocketsPerPart, int n, int m);

#endif