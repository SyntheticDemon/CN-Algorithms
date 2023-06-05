#ifndef LSRPHPP
#define LSRPHPP
#include <vector>
#include "topology.hpp"
#include <sstream>
using namespace std;
#include <iostream>
#include <chrono>
#define INF 100000
using namespace std;

class LSRP
{
public:
    LSRP(vector<vector<int>> graph, int source_id);
    void lsrpAlgorithm(vector<vector<int>> graph, int source);
    void profile();
    double taken;
    int minimumDistance(vector<int> distances, vector<bool> visitedNodes);
    void ShortestPath(vector<int> distances, vector<int> parent, int source);
    void iterationLspr(vector<int> distances, int ItrNum);
};
#endif