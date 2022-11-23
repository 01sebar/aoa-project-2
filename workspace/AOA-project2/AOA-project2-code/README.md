# Analysis-of-Algorithms-Project-2

To compile the program using this command: 
</br> `$ make` </br>
or
</br> `$ g++ -std=c++11 -o robot main.cpp omnidroids.cpp robotomaton.cpp`

To run the program:
- Include input.txt to run an input file for the program.
- In addition, you could modify that input file with other inputs. 
- run `./robot` to see the output file.

input.txt file must look like this:
```
4

omnidroid
8 12
0 1
0 1
0 2
0 2
4 6
5 6
1 7
1 7
2 7
2 7
3 7
6 7
4
2
6
24
14
5
3
6

robotomaton
4
3 0
2 1
10 1
7 3

omnidroid
5 5
0 1
0 1
1 4
2 3
3 4
2
23
11
11
2

robotomaton
5
3 0
11 0
31 1
29 2
5 4
```

Expected Output written in Output.txt file:
```
100
30
51
143
```
