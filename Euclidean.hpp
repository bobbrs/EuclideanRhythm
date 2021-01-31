#ifndef Euclidean_hpp
#define Euclidean_hpp

#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <iterator>
#include <cmath>

#include <stdio.h>

using namespace std;

typedef vector<bool> group;
typedef vector<group> groups;

class Euclidean {
public:
    void Generate(int steps, int pulses, int offset);
    group GetRhythm();
    string str();
private:
    group _rhythm;
    groups _Generate(groups firstGroups, groups lastGroups);
};

#endif /* Euclidean_hpp */
