#include <iostream>

struct part {
    int i;
    int j;
};

int omnidroids(part* parts, int* sprocketsPerPart, int n, int m);

int main() {
    // TODO implement file reading to create following data structs
    int n = 8;
    int m = 12;
    int sprocketsPerPart[] = {4, 2, 6, 24, 14, 5, 3, 6}; // length of this will be n

    // 0 1
    part part1;
    part1.i = 0;
    part1.j = 1;
    // 0 1
    part part2;
    part2.i = 0;
    part2.j = 1;
    // 0 2
    part part3;
    part3.i = 0;
    part3.j = 2;
    // 0 2
    part part4;
    part4.i = 0;
    part4.j = 2;
    // 4 6
    part part5;
    part5.i = 4;
    part5.j = 6;
    // 5 6
    part part6;
    part6.i = 5;
    part6.j = 6;
    // 1 7
    part part7;
    part7.i = 1;
    part7.j = 7;
    // 1 7
    part part8;
    part8.i = 1;
    part8.j = 7;
    // 2 7
    part part9;
    part9.i = 2;
    part9.j = 7;
    // 2 7
    part part10;
    part10.i = 2;
    part10.j = 7;
    // 3 7
    part part11;
    part11.i = 3;
    part11.j = 7;
    // 6 7
    part part12;
    part12.i = 6;
    part12.j = 7;

    part parts[] = {part1, part2, part3, part4, part5, part6, part7, part8, part9, part10, part11, part12};

    return 0;
}

int omnidroids(part* parts, int* sprocketsPerPart, int n, int m) {
    return 0;
}