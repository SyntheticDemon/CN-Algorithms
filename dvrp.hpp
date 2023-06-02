#ifndef DVRPHPP
#define DVRPHPP
#include <vector>
#include "topology.hpp"
using namespace std;
#include <iostream>
#define INF 100000
using namespace std;

class DVRP
{
public:
    int node_count;
    int source;
    double taken;
    Topology *topology;
    vector<int> distances;
    vector<int> parents;
    DVRP(int node_count, int source, Topology *topology);
    void report();
    void profile();
};
#endif